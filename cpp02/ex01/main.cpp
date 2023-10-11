#include <iostream>

#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed const b(10);
  Fixed const c(42.42f);
  Fixed const d(b);
  a = Fixed(1234.4321f);

  // Test << operator
  std::cout << "a is " << a << std::endl;

  // Test fixed-point value to integer value
  std::cout << "a is " << a.toInt() << " as integer" << std::endl;

  // Test fixed-point value to floating point value
  std::cout << "a is " << a.toFloat() << " as floating point" << std::endl;

  return 0;
}
