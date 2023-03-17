#ifndef COMPLEX_HPP
#define COMPLEX_HPP

template<typename T>
class Complex
{
  T r_;
  T i_;

 public:
  Complex(T x = T{}, T y = T{})
      : r_{x}
      , i_{y}
  {}
  auto real() const
  {
    return r_;
  }
  auto imag() const
  {
    return i_;
  }
};

template<typename T>
auto norm2(Complex<T> const& c)
{
  return c.real() * c.real() + c.imag() * c.imag();
}

template<typename T>
auto operator+(Complex<T> const& c1, Complex<T> const& c2)
{
  return Complex{c1.real() + c2.real(), c1.imag() + c2.imag()};
}

template<typename T>
auto operator-(Complex<T> const& c)
{
  return Complex{-c.real(), -c.imag()};
}

template<typename T>
auto operator-(Complex<T> const& c1, Complex<T> const& c2)
{
  return c1 + (-c2);
}

template<typename T>
auto operator*(Complex<T> const& c1, Complex<T> const& c2)
{
  return Complex{c1.real() * c2.real() - c1.imag() * c2.imag(),
                 c1.real() * c2.imag() + c1.imag() * c2.real()};
}

template<typename T>
auto operator==(Complex<T> const& c1, Complex<T> const& c2)
{
  return c1.real() == c2.real() && c1.imag() == c2.imag();
}

template<typename T>
auto operator!=(Complex<T> const& c1, Complex<T> const& c2)
{
  return !(c1 == c2);
}

#endif
