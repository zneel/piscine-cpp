#include <iostream>

#include "Point.hpp"

float my_abs(float const f) { return f < 0 ? -f : f; }

// https://flexbooks.ck12.org/cbook/ck-12-cbse-math-class-10/section/7.4/primary/lesson/references-for-advanced-understanding/
float area(Point const a, Point const b, Point const c) {
  return (.5f *
          (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
           b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
           c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())));
}

bool inside(float p) { return p > 0 && p < 1; }

// https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-rendering-a-triangle/barycentric-coordinates.html
bool bsp(Point const a, Point const b, Point const c, Point const point) {
  std::cout << a << b << c << point << std::endl;

  float abcArea = my_abs(area(a, b, c));
  float pbcArea = my_abs(area(point, b, c));
  float pcaArea = my_abs(area(point, c, a));
  float pabArea = my_abs(area(point, a, b));
  float u = pbcArea / abcArea;
  float v = pcaArea / abcArea;
  float w = pabArea / abcArea;
  return inside(u) && inside(v) && inside(w);
}