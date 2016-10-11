class Vector
{
  int* ints;
  int size;

public:
  explicit Vector(int size_) : ints { new int[size_] }, size { size_ } {}

  Vector(Vector const & rhs) : ints { new int[rhs.size] }, size { rhs.size }
  {
    for (auto i = 0; i != size; ++i)
      ints[i] = rhs.ints[i];
  }

  auto operator=(Vector const & rhs) -> Vector &
  {
    auto is = new int[rhs.size];
    for (auto i = 0; i != rhs.size; ++i)
      is[i] = rhs.ints[i];
    delete[] ints;
    ints = is;
    size = rhs.size;
    return *this;
  }

  ~Vector()
  {
    delete[] ints;
  }
};

auto main() -> int
{
  auto v1 = Vector { 42 };
  auto v2 = Vector { 42 };

  v1 = v2;
}