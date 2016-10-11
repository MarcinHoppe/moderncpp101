#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <tuple>

using std::string;
using std::vector;
using std::tuple;
using std::pair;
using std::cout;
using std::cin;
using std::endl;
using std::get;
using std::tie;
using std::make_tuple;

auto main() -> int
{
  auto phone_book = vector<pair<string, int>>
  {
    { "Marcin Hoppe",      111222333 },
    { "Bjarne Stroustrup", 222333444 },
    { "Herb Sutter",       333444555 }
  };

  auto const & entry = phone_book[0];
  cout << entry.first << ": " << entry.second << endl;

  auto phone_book2 = vector<tuple<string, int, int>>
  {
    make_tuple( "Marcin Hoppe",      111222333, 48 ),
    make_tuple( "Bjarne Stroustrup", 222333444, 48 ),
    make_tuple( "Herb Sutter",       333444555, 48 )
  };

  auto const & entry2 = phone_book2[0];
  cout << get<0>(entry2) << ": (" << get<2>(entry2) << ") " << get<1>(entry2) << endl;

  string name;
  int code, number;
  tie(name, number, code) = entry2;
  cout << name << ": (" << code << ") " << number << endl;
}