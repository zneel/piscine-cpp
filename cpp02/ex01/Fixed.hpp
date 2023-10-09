#pragma once

#include <ostream>
class Fixed {
 public:
  Fixed();
  Fixed(int const i);
  Fixed(float const f);
  Fixed(const Fixed &f);
  Fixed &operator=(Fixed const &other);
  ~Fixed();

  int getRawBits() const;
  void setRawBits(int const raw);
  float toFloat() const;
  int toInt() const;

 private:
  int fp_;
  static const int fb_ = 8;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fp);
