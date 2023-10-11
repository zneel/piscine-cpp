#pragma once

#include <ostream>

#include "Fixed.hpp"
class Point {
 public:
  Point();
  Point(float const x, float const y);
  Point(Point const &);
  Point &operator=(const Point &);
  ~Point();
  Fixed getX() const;
  Fixed getY() const;

 private:
  Fixed const x_;
  Fixed const y_;
};

std::ostream &operator<<(std::ostream &os, Point const &p);
