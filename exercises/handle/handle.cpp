#include <iostream>

#include <dlfcn.h>

extern "C"
{
  typedef void (*init_or_release_t)();
  typedef int (*shared_foo_t)();
}

using std::cout;
using std::endl;

auto main() -> int
{
  auto so_handle = dlopen("cygSharedLibrary.dll", RTLD_NOW);
  
  init_or_release_t init = (init_or_release_t) dlsym(so_handle, "Init");
  init_or_release_t release = (init_or_release_t) dlsym(so_handle, "Release");
  shared_foo_t shared_foo = (shared_foo_t) dlsym(so_handle, "SharedFoo");
  
  init();
  cout << "SharedFoo returned " << shared_foo() << endl;
  release();
  
  dlclose(so_handle);
}