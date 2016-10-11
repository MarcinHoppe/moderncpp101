#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

template <typename Container>
using iterator = typename Container::iterator;

template <typename Container, typename Value>
auto find_all(Container & container, Value value) -> vector<iterator<Container>>
{
  auto ret = vector<iterator<Container>> {};

  for (auto i = container.begin(); i != container.end(); ++i)
    if (*i == value) ret.push_back(i);

  return ret;
}

auto main() -> int
{
  auto s = string { "Ala ma kota" };
  for (auto i : find_all(s, 'a'))
    cout << *i;
  cout << endl;

  auto vs = vector<string> { "Ala", "ma", "kota", "Ala" };
  for (auto i : find_all(vs, "Ala"))
    cout << *i;
  cout << endl;
}
