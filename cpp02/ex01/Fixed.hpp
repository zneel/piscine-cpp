#pragma once

#include <cmath>
#include <iostream>
#include <ostream>
#include <sstream>

class Fixed {
 public:
  Fixed();
  Fixed(int const i);
  Fixed(float const f);
  Fixed(const Fixed &other);
  Fixed &operator=(Fixed const &other);
  ~Fixed();

  int getRawBits() const;
  void setRawBits(int const raw);
  float toFloat() const;
  int toInt() const;

 private:
  int fixedPoint_;
  static const int fractionalBits_ = 8;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fp);
