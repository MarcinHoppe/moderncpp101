#include "static_library.h"

#include <iostream>

using std::cout;
using std::endl;

int StaticLibrary::Foo()
{
  auto ret_val = 42;
  cout << "StaticLibrary::Foo() returns " << ret_val << endl;
  return ret_val;
}