// Zadanie:
// Nalezy przepisac ponizszy program tak, zeby nie zawieral zadnej
// jawnej petli. Nalezy posluzyc sie algorytmami z biblioteki standardowej.
// 
// Na ekranie powinno pojawic sie:
// *********
// *1245689*
// *********
// Liste i opisy algorytmow mozna znalezc tutaj:
// http://en.cppreference.com/w/cpp/algorithm

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;

auto main() -> int
{
  auto ints = vector<int> { 5, 2, 4, 6, 8, 1, 9 };

  auto swapped = true;
  auto j = int { 0 };
  auto tmp = int {};
  while (swapped)
  {
    swapped = false;
    j++;
    for (auto i = 0; i < ints.size() - j; ++i) 
    {
      if (ints[i] > ints[i + 1])
      {
        tmp = ints[i];
        ints[i] = ints[i + 1];
        ints[i + 1] = tmp;
        swapped = true;
      }
    }
  }
  
  auto text = string {};
  for (auto i = 0; i < ints.size(); ++i)
    text.push_back((ints[i] + '0'));
  
  auto lines = vector<string> {};
  
  auto frame = string {};
  frame.push_back('*');
  for (auto i = 0; i < text.length(); ++i)
    frame.push_back('*');
  frame.push_back('*');
  frame.push_back('\n');

  auto decorated_text = string {};
  decorated_text.push_back('*');
  for (auto i = 0; i < text.length(); ++i)
    decorated_text.push_back(text[i]);
  decorated_text.push_back('*');
  decorated_text.push_back('\n');
  
  lines.push_back(frame);
  lines.push_back(decorated_text);
  lines.push_back(frame);
  
  for (auto const & line : lines)
    cout << line;
}