// [FAZA 1]
//#include "static_library.h"

// [FAZA 2]
//extern "C" {
//#include "shared_library.h"
//}

#include <iostream>

using std::cout;
using std::endl;

auto main() -> int
{
  cout << "Hello, CMake!" << endl;
  
  // [FAZA 1]
  // auto static_val = StaticLibrary::Foo();
  // cout << "static_val=" << static_val << endl;

  // [FAZA 2]  
  // Init();
  // static_val = SharedFoo();
  // cout << "static_val=" << static_val << endl;
  // Release();
}