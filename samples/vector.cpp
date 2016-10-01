#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::istream;

struct Entry
{
  string name;
  int phone;
};

auto operator>>(istream& in, Entry& entry) -> istream&
{
  in >> entry.name >> entry.phone;
  return in;
}

auto print(vector<Entry> const & phone_book) -> void
{
  for (int i = 0; i != phone_book.size(); ++i)
    cout << phone_book[i].name << ": " << phone_book[i].phone << endl;
}

auto print2(vector<Entry> const & phone_book) -> void
{
  for (auto const & entry : phone_book)
    cout << entry.name << ": " << entry.phone << endl;
}

auto read() -> vector<Entry>
{
  auto books = vector<Entry> { };
  for (Entry e; cin >> e;)
    books.push_back(e);
  return books;
}

auto main() -> int
{
  auto phone_book = vector<Entry>
  { 
    { "Marcin Hoppe",      111222333 },
    { "Bjarne Stroustrup", 222333444 },
    { "Herb Sutter",       333444555 }
  };
  
  print(phone_book);
  print2(phone_book);
  
  auto phone_book2 = read();
  print(phone_book2);
}
