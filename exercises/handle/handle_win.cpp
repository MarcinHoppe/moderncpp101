#include <iostream>

#include <windows.h>

extern "C"
{
  typedef void (*init_or_release_t)();
  typedef int (*shared_foo_t)();
}

using std::cout;
using std::endl;

auto main() -> int
{
  auto dll_handle = ::LoadLibrary("SharedLibrary.dll");

  init_or_release_t init = (init_or_release_t) ::GetProcAddress(dll_handle, "Init");
  init_or_release_t release = (init_or_release_t) ::GetProcAddress(dll_handle, "Release");
  shared_foo_t shared_foo = (shared_foo_t) ::GetProcAddress(dll_handle, "SharedFoo");

  init();
  cout << "SharedFoo returned " << shared_foo() << endl;
  release();

  ::FreeLibrary(dll_handle);
}