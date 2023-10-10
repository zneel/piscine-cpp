#include "Point.hpp"

#include <iostream>

Point::Point() {}

Point::Point(float const x, float const y) : x_(Fixed(x)), y_(Fixed(y)) {}

Point::Point(Point const &other) : x_(other.x_), y_(other.y_) { *this = other; }

Point &Point::operator=(const Point &other) {
  if (this == &other) return *this;
  return *this;
}

Point::~Point() {}
Fixed Point::getX() const { return this->x_; };
Fixed Point::getY() const { return this->y_; };

std::ostream &operator<<(std::ostream &os, Point const &p) {
  os << "(" << p.getX() << "," << p.getY() << ")";
  return os;
}
