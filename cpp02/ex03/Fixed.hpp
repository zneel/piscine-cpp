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
  Fixed(Fixed const &);
  Fixed &operator=(Fixed const &);
  ~Fixed();

  bool operator>(Fixed const &fp) const;
  bool operator<(Fixed const &fp) const;
  bool operator>=(Fixed const &fp) const;
  bool operator<=(Fixed const &fp) const;
  bool operator==(Fixed const &fp) const;
  bool operator!=(Fixed const &fp) const;

  Fixed operator+(Fixed const &fp);
  Fixed operator-(Fixed const &fp);
  Fixed operator*(Fixed const &fp);
  Fixed operator/(Fixed const &fp);

  Fixed &operator++();    // prefix
  Fixed &operator--();    // prefix
  Fixed operator++(int);  // postfix
  Fixed operator--(int);  // postfix

  static Fixed &min(Fixed &a, Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);

  static Fixed const &min(Fixed const &a, Fixed const &b);
  static Fixed const &max(Fixed const &a, Fixed const &b);

  int getRawBits() const;
  void setRawBits(int const raw);
  float toFloat() const;
  int toInt() const;

 private:
  int fixedPoint_;
  static const int fractionalBits_ = 8;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fp);
