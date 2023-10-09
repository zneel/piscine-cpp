#include <iostream>

#include "Fixed.hpp"

int main() {
  // Test default constructor
  Fixed f1;
  std::cout << "f1: Default constructor: " << f1.getRawBits() << std::endl;
  std::cout << "==========================================" << std::endl;
  // Test integer constructor
  Fixed f2(10);
  std::cout << "f2: Integer constructor: " << f2.getRawBits() << std::endl;
  std::cout << "==========================================" << std::endl;

  // Test float constructor
  Fixed f3(3.14159f);
  std::cout << "f3: Float constructor: " << f3.toFloat() << std::endl;
  std::cout << "==========================================" << std::endl;

  // Test copy constructor
  Fixed f4(f3);
  std::cout << "f4: Copy constructor: " << f4.getRawBits() << std::endl;
  std::cout << "==========================================" << std::endl;

  // Test deep copy constructor
  Fixed f5 = f4;
  std::cout << "f5: Deep copy constructor: " << f5.getRawBits() << std::endl;

  // Modify the value of f4
  f4.setRawBits(20 * (1 << 8));
  std::cout << "Changing f4 to: " << f4.getRawBits() << std::endl;

  // Check if the value of f5 has changed
  std::cout << "Deep copy constructor (after modifying f4): " << f5.getRawBits()
            << std::endl;

  // Test setters and getters
  f1.setRawBits(10.5f * (1 << 8));
  std::cout << "setRawBits(): " << f1.getRawBits() << std::endl;
  std::cout << "toFloat(): " << f1.toFloat() << std::endl;
  std::cout << "toInt(): " << f1.toInt() << std::endl;
  std::cout << "==========================================" << std::endl;

  // Test operators
  Fixed f6 = f1 + f2;
  std::cout << "f6: operator+(): " << f6.getRawBits() << std::endl;
  f6 = f1 - f2;
  std::cout << "f6: operator-(): " << f6.getRawBits() << std::endl;
  f6 = f1 * f2;
  std::cout << "f6: operator*(): " << f6.getRawBits() << std::endl;
  f6 = f1 / f2;
  std::cout << "f6: operator/(): " << f6.getRawBits() << std::endl;
  std::cout << "==========================================" << std::endl;

  // Test comparison operators
  std::cout << "f1: " << f1.getRawBits() << " f2: " << f2.getRawBits()
            << " operator<(f1 < f2): " << (f1 < f2) << std::endl;
  std::cout << "f1: " << f1.getRawBits() << " f2: " << f2.getRawBits()
            << " operator>(f1 > f2): " << (f1 > f2) << std::endl;
  std::cout << "f1: " << f1.getRawBits() << " f2: " << f2.getRawBits()
            << " operator<=(f1 <= f2): " << (f1 <= f2) << std::endl;
  std::cout << "f1: " << f1.getRawBits() << " f2: " << f2.getRawBits()
            << " operator>=(f1 >= f2): " << (f1 >= f2) << std::endl;
  std::cout << "f1: " << f1.getRawBits() << " f2: " << f2.getRawBits()
            << " operator==(f1 == f2): " << (f1 == f2) << std::endl;
  std::cout << "f1: " << f1.getRawBits() << " f2: " << f2.getRawBits()
            << " operator!=(f1 != f2): " << (f1 != f2) << std::endl;
  std::cout << "==========================================" << std::endl;

  // Test increment and decrement operators postfix
  std::cout << "f1: " << f1.getRawBits() << std::endl;
  f1++;
  std::cout << "f1++: operator++(int): " << f1.getRawBits() << std::endl;
  f1--;
  std::cout << "f1--: operator--(int): " << f1.getRawBits() << std::endl;
  // Test increment and decrement operators prefix
  std::cout << "f1: " << f1.getRawBits() << std::endl;
  ++f1;
  std::cout << "++f1: operator++(): " << f1.getRawBits() << std::endl;
  --f1;
  std::cout << "--f1: operator--(): " << f1.getRawBits() << std::endl;
  std::cout << "==========================================" << std::endl;

  // Test min() and max() functions
  Fixed f7 = Fixed::min(f1, f2);
  Fixed f8 = Fixed::max(f1, f2);
  std::cout << "f1: " << f1.getRawBits() << " f2: " << f2.getRawBits()
            << " min(): " << f7.getRawBits() << std::endl;
  std::cout << "f1: " << f1.getRawBits() << " f2: " << f2.getRawBits()
            << " max(): " << f8.getRawBits() << std::endl;
  std::cout << "==========================================" << std::endl;

  // Test output stream operator
  std::cout << "operator<<(): " << f3 << std::endl;
  std::cout << "==========================================" << std::endl;

  return 0;
}
