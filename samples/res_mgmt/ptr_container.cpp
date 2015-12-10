#include <boost/ptr_container/ptr_vector.hpp>
#include <string>
#include <iostream>

using boost::ptr_vector;
using std::string;
using std::cout;
using std::endl;

auto main() -> int
{
  auto vec = ptr_vector<int> {};
  for (auto i = 0; i < 10; ++i)
    vec.push_back(new int { i });
  cout << vec.back() << endl;
}