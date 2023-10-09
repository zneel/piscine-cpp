#pragma once

#include "Fixed.hpp"
class Point {
 public:
  Point();
  Point(float const x, float const y);
  Point(Point const &);
  Point &operator=(const Point &);
  ~Point();

 private:
  Fixed const x_;
  Fixed const y_;
};
