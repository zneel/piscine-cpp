#include <iostream>

#include "Point.hpp"

float my_abs(float const f) { return f < 0 ? -f : f; }

/**
 * @brief Calculate the area of a triangle
 *
 * @param a Point a
 * @param b Point b
 * @param c Point c
 * @return float The area of the triangle
 */
float area(Point const a, Point const b, Point const c) {
  return (0.5f *
          (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
           b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
           c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())));
}

bool inside(float p) { return p > 0 && p < 1; }

/**
 * @brief Check if a point is inside a triangle
 *
 * @param a Point a of the triangle
 * @param b Point b of the triangle
 * @param c Point c of the triangle
 * @param point The point to check
 * @return true The point is inside the triangle
 * @return false The point is outside the triangle
 */
bool bsp(Point const a, Point const b, Point const c, Point const point) {
  float abcArea = my_abs(area(a, b, c));
  float pbcArea = my_abs(area(point, b, c));
  float pcaArea = my_abs(area(point, c, a));
  float pabArea = my_abs(area(point, a, b));
  float u = pbcArea / abcArea;
  float v = pcaArea / abcArea;
  float w = pabArea / abcArea;
  return inside(u) && inside(v) && inside(w);
}
