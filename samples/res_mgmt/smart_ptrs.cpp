#include <memory>
#include <stdexcept>
#include <string>

using std::unique_ptr;
using std::shared_ptr;
using std::make_shared;
using std::runtime_error;
using std::string;

struct X
{
  auto do_something() const -> void
  {
    throw runtime_error { "in do_something" };
  }
};

auto protect_resource(int i, int j) -> void
{
  auto p = new X;
  auto sp = unique_ptr<X> { new X };
  
  if (i < 99) throw runtime_error { "in protect_resource" };
  if (j < 77) return;
  
  p->do_something();
  sp->do_something();
  
  delete p;
}

struct Entry
{
  string name;
  int phone;
  
  Entry(string const & name_, int phone_) : name { name_ }, phone { phone_ } {}
};

auto foo(shared_ptr<Entry> entry_ptr) -> void
{
}

auto bar(shared_ptr<Entry> entry_ptr) -> void
{
}

auto protect_shared_resource() -> void
{
  auto sp = make_shared<Entry>("Marcin Hoppe", 123456789);
  foo(sp);
  bar(sp);
}

auto main() -> int
{

}