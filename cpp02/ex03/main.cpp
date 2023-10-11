#include <iostream>

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
  {  // outside (on a line)
    Point a(0, 0);
    Point b(4, 0);
    Point c(0, 4);
    Point p(2, 2);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << p << std::endl;
    if (bsp(a, b, c, p))
      std::cout << "The Point P" << p << " is inside" << std::endl;
    else
      std::cout << "The Point P" << p << " is outside or on a line"
                << std::endl;
  }
  {  // outside
    Point a(0, 0);
    Point b(4, 0);
    Point c(0, 4);
    Point p(5, 5);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << p << std::endl;
    if (bsp(a, b, c, p))
      std::cout << "The Point P" << p << " is inside" << std::endl;
    else
      std::cout << "The Point P" << p << " is outside or on a line"
                << std::endl;
  }
  {  // outside (on the vertex)
    Point a(0, 0);
    Point b(4, 0);
    Point c(0, 4);
    Point p(0, 0);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << p << std::endl;
    if (bsp(a, b, c, p))
      std::cout << "The Point P" << p << " is inside" << std::endl;
    else
      std::cout << "The Point P" << p << " is outside or on a line"
                << std::endl;
  }
  {  // outside (on edge)
    Point a(0, 0);
    Point b(4, 0);
    Point c(0, 4);
    Point p(2, 0);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << p << std::endl;
    if (bsp(a, b, c, p))
      std::cout << "The Point P" << p << " is inside" << std::endl;
    else
      std::cout << "The Point P" << p << " is outside or on a line"
                << std::endl;
  }
  {  // outside
    Point a(-1, -1);
    Point b(3, -1);
    Point c(-1, 3);
    Point p(1, 1);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << p << std::endl;
    if (bsp(a, b, c, p))
      std::cout << "The Point P" << p << " is inside" << std::endl;
    else
      std::cout << "The Point P" << p << " is outside or on a line"
                << std::endl;
  }
  {  // inside
    Point a(0, 0);
    Point b(4, 0);
    Point c(0, 4);
    Point p(1.5f, 1);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << p << std::endl;
    if (bsp(a, b, c, p))
      std::cout << "The Point P" << p << " is inside" << std::endl;
    else
      std::cout << "The Point P" << p << " is outside or on a line"
                << std::endl;
  }
  {  // inside
    Point a(-1, -1);
    Point b(3, -1);
    Point c(-1, 3);
    Point p(0.34f, 0.48f);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << p << std::endl;
    if (bsp(a, b, c, p))
      std::cout << "The Point P" << p << " is inside" << std::endl;
    else
      std::cout << "The Point P" << p << " is outside or on a line"
                << std::endl;
  }
  return 0;
}
