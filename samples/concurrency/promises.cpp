#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <iostream>
#include <functional>

using std::vector;
using std::promise;
using std::future;
using std::thread;
using std::ref;
using std::cout;
using std::cerr;
using std::endl;
using std::accumulate;

using iter = vector<int>::iterator;

auto accum(iter first, iter last, promise<int> & accumulate_promise) -> void
{
  auto sum = accumulate(first, last, 0);
  accumulate_promise.set_value(sum);
}

int main()
{
  auto ints = vector<int> { 1, 2, 3, 4, 5, 6 };
  promise<int> accumulate_promise;
  future<int> accumulate_future = accumulate_promise.get_future();
  auto worker = thread { accum, ints.begin(), ints.end(), ref(accumulate_promise) };
  try
  {
    cout << "result=" << accumulate_future.get() << endl;
  }
  catch (...)
  {
    cerr << "error" << endl;
  }
  worker.join();
}