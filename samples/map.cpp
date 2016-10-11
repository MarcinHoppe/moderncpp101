#include <iostream>
#include <string>
#include <map>

using std::string;
using std::map;
using std::cout;
using std::cin;
using std::endl;

auto get_number(map<string, int> const & phone_book, string const & name) -> int
{
  auto entry = phone_book.find(name);

  if (entry == phone_book.end())
    return -1;

  return entry->second;
}

auto main() -> int
{
  auto phone_book = map<string, int>
  {
    { "Marcin Hoppe",      111222333 },
    { "Bjarne Stroustrup", 222333444 },
    { "Herb Sutter",       333444555 }
  };

  cout << phone_book["Marcin Hoppe"] << endl;
  cout << get_number(phone_book, "Bjarne S") << endl;
}