#include "static_library.h"

#include <iostream>

using std::cout;
using std::endl;

auto main() -> int
{
  cout << "Hello, compiler!" << endl;
  
  auto static_val = StaticLibrary::Foo();
  cout << "static_val=" << static_val << endl;
}