#pragma once
#include <iostream>

class Fixed {
 public:
  Fixed();
  Fixed(const Fixed &other);
  Fixed &operator=(Fixed const &other);
  ~Fixed();

  int getRawBits() const;
  void setRawBits(int const raw);

 private:
  int fixedPoint_;
  static const int fractionalBits_ = 8;
};
