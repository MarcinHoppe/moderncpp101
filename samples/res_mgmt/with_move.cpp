#include <iostream>

using std::cout;
using std::endl;

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
    return ints[index];
  }

  auto operator[](int index) const -> int
  {
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

auto main() -> int
{
  auto v1 = Vector { 42 };
  auto v2 = Vector { 42 };
  auto v3 = Vector { 42 };
  auto v4 = v1 + v2 + v3;
  cout << v4.get_size() << endl;
}