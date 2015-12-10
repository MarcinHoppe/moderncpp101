#include <algorithm>
#include <map>
#include <string>
#include <iostream>

using std::map;
using std::string;
using std::pair;
using std::find_if;
using std::begin;
using std::end;
using std::cout;
using std::endl;

struct greater_than
{
  int value;
  
  greater_than(int value_) : value { value_ }
  {
  }
  
  auto operator()(pair<string, int> const & element) const -> bool
  {
    return element.second > value;
  }
};

auto find_greater_than_20(map<string, int> & scores) -> void
{
  auto element = find_if(begin(scores), end(scores), greater_than { 20 });
  if (element != end(scores))
  {
    cout << element->first << endl;
  }
}

auto find_greater_than_limit(map<string, int> & scores, int score_limit) -> void
{
  auto pred = [score_limit](pair<string, int> const & element) -> bool 
  {
    return element.second > score_limit;
  };
  auto element = find_if(begin(scores), end(scores), pred);
  if (element != end(scores))
  {
    cout << element->first << endl;
  }
}

auto main() -> int
{
  auto scores = map<string, int>
  {
    { "Marcin", 10 },
    { "Tomek" , 12 },
    { "Pawel" , 33 }
  };
  
  find_greater_than_20(scores);
  find_greater_than_limit(scores, 20); 
}