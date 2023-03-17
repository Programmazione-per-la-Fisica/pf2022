#include "complex.hpp"
#include "doctest.h"

TEST_CASE("Testing Complex")
{
  Complex<double> c{};
  CHECK(c.real() == 0.);
  CHECK(c.imag() == 0.);
  CHECK(norm2(c) == 0.);
  CHECK(norm2(Complex{1., 2.}) == 5.);
  CHECK((Complex{1., 2.} + Complex{3., 4.} == Complex{4., 6.}));
  // ...
}
