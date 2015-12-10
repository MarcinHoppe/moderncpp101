#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using std::string;
using std::unordered_map;
using std::unordered_set;
using std::cout;
using std::cin;
using std::endl;
using std::hash;

auto get_number(unordered_map<string, int> const & phone_book, string const & name) -> int
{
  auto entry = phone_book.find(name);
  
  if (entry == phone_book.end())
    return -1;
    
  return entry->second;
}

auto main() -> int
{
  auto phone_book = unordered_map<string, int>
  { 
    { "Marcin Hoppe",     111222333 },
    { "Tomek Woroniecki", 222333444 },
    { "Pawel Zieminski",  333444555 }
  };
  
  cout << phone_book["Marcin Hoppe"] << endl;
  cout << get_number(phone_book, "Bjarne S") << endl;
}