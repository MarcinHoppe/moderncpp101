#include <thread>
#include <mutex>
#include <iostream>
#include <array>
#include <functional>

using std::thread;
using std::mutex;
using std::unique_lock;
using std::lock;
using std::defer_lock;
using std::cout;
using std::endl;
using std::array;
using std::ref;

int global_data = 0;
mutex global_mutex;

auto modify_global_data() -> void
{
  auto lock = unique_lock<mutex> { global_mutex };
  ++global_data;
}

struct Record
{
  mutex m;
  int   value = 7;
};

auto modify(Record & one, Record & two) -> void
{
  auto lock_one = unique_lock<mutex> { one.m, defer_lock };
  auto lock_two = unique_lock<mutex> { two.m, defer_lock };
  
  lock(lock_one, lock_two);
  
  auto one_old = one.value, two_old = two.value;
  one.value = two.value = one_old + two_old;
}

auto main() -> int
{
  auto workers = array<thread, 2> {
    thread { modify_global_data },
    thread { modify_global_data }
  };
  for (auto & worker : workers)
    worker.join();
  cout << global_data << endl;
  
  Record r1, r2;
  auto record_workers = array<thread, 2> {
    thread { modify, ref(r1), ref(r2) },
    thread { modify, ref(r2), ref(r1) }
  };
  for (auto & worker : record_workers)
    worker.join();
  cout << r1.value << ", " << r2.value << endl;
}