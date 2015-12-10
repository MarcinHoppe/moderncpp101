#include <iostream>
#include <stdexcept>

using std::cout;
using std::cerr;
using std::endl;
using std::out_of_range;
using std::logic_error;

class Vector
{
  int* ints;
  int size;
  
public:
  explicit Vector(int size_) : ints { new int[size_] }, size { size_ } {}
  
  Vector(Vector const & rhs) : ints { new int[rhs.size] }, size { rhs.size }
  {
    cout << "a";
    for (auto i = 0; i != size; ++i)
      ints[i] = rhs.ints[i];
  }
  
  auto operator=(Vector const & rhs) -> Vector &
  {
    cout << "b";
    auto is = new int[rhs.size];
    for (auto i = 0; i != rhs.size; ++i)
      is[i] = rhs.ints[i];
    delete[] ints;
    ints = is;
    size = rhs.size;
    return *this;
  }
  
  Vector(Vector && rhs) : ints { rhs.ints }, size { rhs.size }
  {
    cout << "c";
    rhs.ints = nullptr;
    rhs.size = 0;
  }
  
  auto operator=(Vector && rhs) -> Vector &
  {
    cout << "d";
    ints = rhs.ints;
    size = rhs.size;
    rhs.ints = nullptr;
    rhs.size = 0;
  }
  
  auto operator[](int index) -> int &
  {
    if (index < 0 || index >= size)
      throw out_of_range { "Vector::operator[]" };
    return ints[index];
  }
  
  auto operator[](int index) const -> int
  {
    if (index < 0 || index >= size)
      throw out_of_range { "Vector::operator[] const" };
    return ints[index];
  }
  
  auto get_size() const -> int
  {
    return size;
  }
  
  ~Vector()
  {
    delete[] ints;
  }
};

auto operator+(Vector const & lhs, Vector const & rhs) -> Vector
{
  auto res = Vector { lhs.get_size() };
  
  for (auto i = 0; i != lhs.get_size(); ++i)
    res[i] = lhs[i] + rhs[i];
  
  return res;
}

auto copy_7th(Vector const & v) -> Vector
{
  auto res = Vector { v.get_size() };
  res[6] = v[6];
  return res;
}

auto main() -> int
{
  auto v1 = Vector { 3 };
  try
  {
    auto v2 = copy_7th(v1);
  }
  catch (logic_error const & e)
  {
    cerr << "Error at " << e.what() << endl;
  }
  catch (...)
  {
    cerr << "unknown exception" << endl;
  }
}