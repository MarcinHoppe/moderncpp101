// Zadanie:
// Nalezy sparsowac kazda linie logu, ktora wyglada tak:
// 
// 2012-02-03 18:35:34 SampleClass2 [TRACE] verbose detail for id 1559025043
// 
// i wypisac na ekran jedynie to, ile razy wystapilo zdarzenie na danym poziomie:
// 
// [TRACE] 732
// [DEBUG] 1500
// [INFO] 7

#include <iostream>
#include <string>
#include <regex>
#include <vector>

using std::string;
using std::getline;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

using std::regex;
using std::smatch;
using std::regex_search;

struct LogEvent
{
  string source;
  string level;
};

auto is_match(smatch const & matches) -> bool
{
  return matches.size() > 2 && matches[1].matched && matches[2].matched;
}

auto make_log_event(smatch const & matches) -> LogEvent
{
  auto event = LogEvent {};
  
  event.source = matches[1].str();
  event.level = matches[2].str();
  
  return event;
}

auto main() -> int
{
  auto const pattern = regex { R"((SampleClass[0-9])\s+\[([A-Z]+)\])" };

  // ...
  
  for (string line; getline(cin, line);)
  {
    smatch matches;
    if (regex_search(line, matches, pattern))
    {
      if (is_match(matches))
      {
        auto event = make_log_event(matches);
        // ...
      }
    }
  }
  
  // ...
}