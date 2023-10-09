#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed() : fp_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f) {
  std::cout << "Copy constructor called" << std::endl;
  *this = f;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed &Fixed::operator=(const Fixed &other) {
  if (this == &other) return *this;
  std::cout << "Copy assignment operator called" << std::endl;
  this->setRawBits(other.getRawBits());
  return *this;
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->fp_;
}

void Fixed::setRawBits(int const raw) { this->fp_ = raw; }
