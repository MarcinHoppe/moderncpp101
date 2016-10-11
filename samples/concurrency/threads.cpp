#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>
#include <chrono>
#include <functional>

using std::cout;
using std::endl;
using std::thread;
using std::sort;
using std::vector;
using std::this_thread::sleep_for;
using std::ref;

using namespace std::literals;

auto f() -> void { cout << "Hello, "; }

struct F
{
  auto operator()() -> void { cout << "concurrent world!" << endl; }
};

auto l = []() { cout << "That's all!" << endl; };

auto main() -> int
{
  auto first  = thread { f };
  auto second = thread { F() };
  auto third  = thread { l };

  first.join();
  second.join();
  third.join();

  auto sorter = [](vector<int> & ints) {
    sort(begin(ints), end(ints));
  };
  auto ints = vector<int> {
    4, 5, 6, 7, 1, 2, 3, 8, 9
  };
  auto sort_thread = thread { sorter, ref(ints) };
  sort_thread.detach();
  sleep_for(1s);
}