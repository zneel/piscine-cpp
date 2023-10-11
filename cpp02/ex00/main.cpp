#include <iostream>

#include "Fixed.hpp"

int main(void) {
  std::cout << "=============================" << std::endl;
  // Test the accessors to the raw value
  Fixed a;
  a.setRawBits(10);
  int rawBits = a.getRawBits();
  std::cout << "a.getRawBits() = " << rawBits << std::endl;
  std::cout << "=============================" << std::endl;
  // Test the canonical class elements
  Fixed b(a);  // Test the copy constructor
  b = a;       // Test the copy assignment operator
  // Test the default constructor
  Fixed c;
  int cRawBits = c.getRawBits();
  std::cout << "c.getRawBits() before = " << cRawBits << std::endl;
  c = a;  // Test the copy assignment operator
  cRawBits = c.getRawBits();
  std::cout << "c.getRawBits() after = " << cRawBits << std::endl;
  std::cout << "=============================" << std::endl;
  // Test the destructor
  Fixed *d = new Fixed();
  delete d;
  std::cout << "=============================" << std::endl;

  return 0;
}
