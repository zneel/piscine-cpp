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
  int fp_;
  static const int fb_ = 8;
};