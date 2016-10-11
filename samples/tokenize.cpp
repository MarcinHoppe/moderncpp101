#include <boost/tokenizer.hpp>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

using boost::tokenizer;
using boost::char_separator;
using boost::offset_separator;

auto print_tokens(string const & s) -> void
{
  using tokenizer = tokenizer<char_separator<char>>;
  auto sep = char_separator<char> { " _" };
  auto tokens = tokenizer { s, sep };

  for (auto const & token : tokens)
  {
    cout << token << endl;
  }
}

auto print_tokens2(string const & s) -> void
{
  using tokenizer = tokenizer<offset_separator>;
  int offsets[] = { 2, 1, 3 };
  auto sep = offset_separator { offsets, offsets + 3 };
  auto tokens = tokenizer { s, sep };

  for (auto const & token : tokens)
  {
    cout << token << endl;
  }
}

auto main() -> int
{
  print_tokens("Ala ma_kota");
  print_tokens2("80-298");
}