#pragma once

class Fixed {
 public:
  Fixed();
  Fixed(const Fixed &f);
  ~Fixed();
  Fixed &operator=(Fixed const &other);

  int getRawBits() const;
  void setRawBits(int const raw);

 private:
  int fp_;
  static const int fb_ = 8;
};