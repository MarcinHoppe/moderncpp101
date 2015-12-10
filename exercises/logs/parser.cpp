// Zadanie:
// Nalezy sparsowac kazda linie logu, ktora wyglada tak:
// 
// 2012-02-03 18:35:34 SampleClass2 [TRACE] verbose detail for id 1559025043
// 
// i wypisac na ekran jedynie zrodlo i poziom, na ktorym zalogowano zdarzenie:
// 
// [TRACE] SampleClass2
// 
// Podpowiedz: (SampleClass[0-9])\s+\[([A-Z]+)\]

#include <iostream>
#include <string>
#include <regex>

using std::string;
using std::getline;
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

struct LogEvent
{
  string source;
  string level;
};

auto operator<<(ostream & out, LogEvent const & event) -> ostream &
{
  out << "[" << event.level << "] " << event.source;
}

auto main() -> int
{
  for (string line; getline(cin, line);)
  {
    // ...
  }
}