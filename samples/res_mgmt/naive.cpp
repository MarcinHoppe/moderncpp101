class Vector
{
  int* ints;
  int size;

public:
  explicit Vector(int size_) : ints { new int[size_] }, size { size_ } {}
  ~Vector()
  {
    delete[] ints;
  }
};

auto main() -> int
{
  auto v1 = Vector { 42 };
  auto v2 = v1;
}