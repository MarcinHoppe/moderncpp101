#include <iostream>
#include <string>
#include <list>

using std::string;
using std::list;
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

auto print(list<Entry> const & phone_book) -> void
{
  for (auto e = phone_book.begin(); e != phone_book.end(); ++e)
    cout << e->name << ": " << e->phone << endl;
}

auto read() -> list<Entry>
{
  auto books = list<Entry> { };
  for (Entry e; cin >> e;)
    books.push_back(e);
  return books;
}

auto add_and_remove(
  list<Entry> & phone_book,
  Entry e,
  list<Entry>::iterator at,
  list<Entry>::iterator to_remove) -> void
{
  phone_book.insert(at, e);
  phone_book.erase(to_remove);
}

auto main() -> int
{
  auto phone_book = list<Entry>
  {
    { "Marcin Hoppe",      111222333 },
    { "Bjarne Stroustrup", 222333444 },
    { "Herb Sutter",       333444555 }
  };

  add_and_remove(
    phone_book,
    { "Bjarne S", 999999999 },
    phone_book.end(),
    phone_book.begin());

  print(phone_book);

  auto phone_book2 = read();
  print(phone_book2);
}