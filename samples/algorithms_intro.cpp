#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using std::string;
using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::sort;
using std::copy;
using std::unique_copy;
using std::back_inserter;
using std::begin;
using std::end;
using std::ostream;
using std::ostream_iterator;

struct Entry
{
  string name;
  int phone;
};

auto operator<(Entry const & lhs, Entry const & rhs) -> bool
{
  return lhs.name < rhs.name;
}

auto operator==(Entry const & lhs, Entry const & rhs) -> bool
{
  return lhs.name == rhs.name;
}

auto operator<<(ostream& out, Entry const & e) -> ostream&
{
  out << e.name << ": " << e.phone;
  return out;
}

auto main() -> int
{
  auto phone_book = vector<Entry>
  { 
    { "Marcin Hoppe",     111222333 },
    { "Tomek Woroniecki", 222333444 },
    { "Pawel Zieminski",  333444555 },
    { "Marcin Hoppe",     111222333 },
    { "Pawel Zieminski",  333444555 }
  };
  
  sort(begin(phone_book), end(phone_book));
  
  auto phone_list = list<Entry> {};
  unique_copy(begin(phone_book), end(phone_book), back_inserter(phone_list));
  
  auto out = ostream_iterator<Entry> { cout, "\r\n" };
  copy(begin(phone_list), end(phone_list), out);
}