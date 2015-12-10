#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <iostream>
#include <functional>
 
using std::vector;
using std::async;
using std::cout;
using std::cerr;
using std::endl;
using std::accumulate;
 
using iter = vector<int>::iterator;
 
auto accum(iter first, iter last) -> int
{
  return accumulate(first, last, 0);
}
 
int main()
{
  auto ints = vector<int> { 1, 2, 3, 4, 5, 6 };

  try
  {
    auto const size = ints.size();
    auto first  = async(accum, ints.begin()           , ints.begin() + size / 2);
    auto second = async(accum, ints.begin() + size / 2, ints.end()             );
    
    cout << "result=" << first.get() + second.get() << endl;
  }
  catch (...)
  {
    cerr << "error" << endl;
  }
}