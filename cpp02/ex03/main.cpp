#include <iostream>

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

// https://www.desmos.com/calculator/ymhqcyhfdz
int main() {
  Point a(0, 0);
  Point b(4, 0);
  Point c(0, 4);
  Point p1(2, 2);          // outside (on a line)
  Point p2(5, 5);          // outside
  Point p3(0, 0);          // outside (on the vertex)
  Point p4(2, 0);          // outside (on edge)
  Point p5(-1, -1);        // outside
  Point p6(1.5f, 1);       // inside
  Point p7(0.34f, 0.48f);  // inside

  std::cout << "Testing point " << p1 << std::endl;
  if (bsp(a, b, c, p1)) {
    std::cout << "Inside" << std::endl;
  } else {
    std::cout << "Outside" << std::endl;
  }

  std::cout << "Testing point " << p2 << std::endl;
  if (bsp(a, b, c, p2)) {
    std::cout << "Inside" << std::endl;
  } else {
    std::cout << "Outside" << std::endl;
  }

  std::cout << "Testing point " << p3 << std::endl;
  if (bsp(a, b, c, p3)) {
    std::cout << "Inside" << std::endl;
  } else {
    std::cout << "Outside" << std::endl;
  }

  std::cout << "Testing point " << p4 << std::endl;
  if (bsp(a, b, c, p4)) {
    std::cout << "Inside" << std::endl;
  } else {
    std::cout << "Outside" << std::endl;
  }

  std::cout << "Testing point " << p5 << std::endl;
  if (bsp(a, b, c, p5)) {
    std::cout << "Inside" << std::endl;
  } else {
    std::cout << "Outside" << std::endl;
  }

  std::cout << "Testing point " << p6 << std::endl;
  if (bsp(a, b, c, p6)) {
    std::cout << "Inside" << std::endl;
  } else {
    std::cout << "Outside" << std::endl;
  }

  std::cout << "Testing point " << p7 << std::endl;
  if (bsp(a, b, c, p7)) {
    std::cout << "Inside" << std::endl;
  } else {
    std::cout << "Outside" << std::endl;
  }
  return 0;
}
