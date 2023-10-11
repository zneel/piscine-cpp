#include <iostream>

#include "Fixed.hpp"

int main() {
  // 42 subject test
  {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
  }
  // My tests
  // Comparison operators
  {
    Fixed a(10);
    Fixed b(20);

    std::cout << "Testing comparison operators:" << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
  }

  // Arithmetic operators
  {
    Fixed a(10);
    Fixed b(20);

    std::cout << "Testing arithmetic operators:" << std::endl;
    std::cout << "a + b: " << (a + b) << std::endl;
    std::cout << "a - b: " << (a - b) << std::endl;
    std::cout << "a * b: " << (a * b) << std::endl;
    std::cout << "a / b: " << (a / b) << std::endl;
  }

  // Increment and decrement operators
  {
    Fixed a(10);

    std::cout << "Testing increment and decrement operators:" << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a--: " << a-- << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "--a: " << --a << std::endl;
  }

  // min and max functions
  {
    Fixed a(10);
    Fixed b(20);

    std::cout << "Testing min and max functions:" << std::endl;
    std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
    std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
  }

  return 0;
}
