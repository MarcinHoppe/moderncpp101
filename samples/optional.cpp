#include <boost/optional.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using std::rand;
using std::srand;
using std::time;
using std::cout;
using std::endl;

using boost::optional;

auto get_even_random_number() -> optional<int>
{
  int i = rand();
  return (i % 2 == 0) ? i : optional<int> {};
}

auto main() -> int
{
  srand(static_cast<unsigned int>(time(0)));
  
  optional<int> i = get_even_random_number();
  if (i)
    cout << *i << endl;
}