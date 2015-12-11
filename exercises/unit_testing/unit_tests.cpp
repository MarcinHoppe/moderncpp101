#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <vector>

using std::vector;

auto factorial(unsigned n) -> unsigned
{
  return n <= 1 ? n : n * factorial(n - 1);
}

TEST_CASE( "Factorials are computed", "[factorial]" )
{
  // ...
  REQUIRE( factorial(1) == 1 );
  // ...
}

TEST_CASE( "vectors can be resized", "[vector]" )
{
  vector<int> v(5);
  
  REQUIRE( v.size() == 5 );
  REQUIRE( v.capacity() >= 5 );
  CHECK( v[0] == 0 );
  
  SECTION( "resizing bigger changes size and capacity" )
  {
    v.resize(10);
  
    REQUIRE( v.size() == 10 );
    REQUIRE( v.capacity() >= 10 );
  }
}

TEST_CASE( "testing boost::gather", "[boost]" )
{
  // http://en.cppreference.com/w/cpp/algorithm/set_symmetric_difference
}