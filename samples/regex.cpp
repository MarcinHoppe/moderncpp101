#include <string>
#include <regex>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

#include <boost/algorithm/string.hpp>

using std::regex;
using std::regex_search;
using std::regex_match;
using std::sregex_iterator;
using std::sregex_token_iterator;
using std::smatch;
using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::boolalpha;
using std::endl;
using std::copy;
using std::ostream_iterator;
using std::vector;

auto find_zip_codes() -> void
{
  auto const pattern = regex { R"(\d{2}-\d{3})" };

  int lineno = 0;
  for (string line; getline(cin, line);)
  {
    ++lineno;
    smatch matches;
    if (regex_search(line, matches, pattern))
    {
      cout << lineno << ": " << matches[0] << endl;
    }
  }
}

auto find_zip_codes_and_cities() -> void
{
  auto const pattern = regex { R"(\d{2}-\d{3}\s+(\w+))" };

  int lineno = 0;
  for (string line; getline(cin, line);)
  {
    ++lineno;
    smatch matches;
    if (regex_search(line, matches, pattern))
    {
      cout << lineno << ": " << matches[0] << endl;
      if (matches.size() > 1 && matches[1].matched)
      {
        cout << "\t: " << matches[1] << endl;
      }
    }
  }
}

auto is_zip_code(string const & s) -> void
{
  auto const pattern = regex { R"(\d{2}-\d{3})" };
  cout << s << " is zip code: "
       << boolalpha << regex_match(s, pattern)
       << endl;
}

auto print_words(string const & s) -> void
{
  auto const pattern = regex { R"((\w+))" };
  auto const end = sregex_iterator {};
  auto iter = sregex_iterator { s.begin(), s.end(), pattern };

  for (auto i = iter; i != end; ++i)
  {
    auto matches = *i;
    cout << matches[1] << endl;
  }
}

auto print_words2(string const & s) -> void
{
  auto const pattern = regex { R"((\w+))" };
  auto const end = sregex_token_iterator {};
  auto iter = sregex_token_iterator { s.begin(), s.end(), pattern, 1 };
  auto out = ostream_iterator<string>(cout, "\r\n");

  copy(iter, end, out);
}

auto join_strings() -> void
{
  auto words = vector<string> { "Ala", "ma", "kota" };
  cout << boost::algorithm::join(words, " ") << endl;
}

auto main() -> int
{
  //find_zip_codes();
  //find_zip_codes_and_cities();
  print_words("Ala ma kota");
  print_words2("Ala ma kota");
  is_zip_code("80-283");
  join_strings();
}