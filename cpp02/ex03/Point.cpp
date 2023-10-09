#include "Point.hpp"

Point::Point() {}
Point::Point(float const x, float const y) : x_(x), y_(y) {}
Point::Point(Point const &other) : x_(other.x_), y_(other.y_) {}
Point &Point::operator=(const Point &other) {
  if (this == &other) return *this;
  (Fixed) this->x_ = other.x_;
  (Fixed) this->y_ = other.y_;
  return *this;
}
Point::~Point() {}
