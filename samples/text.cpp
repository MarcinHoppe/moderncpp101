#include <cctype>
#include <string>
#include <iostream>
#include <cstdio>

using std::string;
using std::cout;
using std::endl;
using std::toupper;
using std::printf;

string compose(string const & name, string const & domain)
{
  return name + "@" + domain;
}

void append_newline(string & s)
{
  s += "\r\n";
}

auto main() -> int
{
  auto const domain = string { "acm.org" };
  auto address = compose("marcin.hoppe", domain);
  append_newline(address);
  cout << address;
  
  auto name = address.substr(0, 12);
  cout << name << endl;
  
  address.replace(13, 7, "gmail.com");
  cout << address;
  
  name[0] = toupper(name[0]);
  cout << name << endl;
  
  if (address == "marcin.hoppe@gmail.com")
    cout << "Yes!" << endl;
  else
    cout << "No!" << endl;
    
  if (address == name)
    cout << "Wrong variable!" << endl;
  else
    cout << "OK!" << endl;
    
  printf("My address is %s", address.c_str());
}