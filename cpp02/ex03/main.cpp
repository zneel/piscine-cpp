#include <iostream>

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
  Point a(-1, 2);
  Point b(4, 3);
  Point c(5, -2);
  Point p(5, -2);
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
  std::cout << p << std::endl;
  if (bsp(a, b, c, p))
    std::cout << "The Point P" << p << " is inside" << std::endl;
  else
    std::cout << "The Point P" << p << " is outside or on a line" << std::endl;
  return 0;
}
