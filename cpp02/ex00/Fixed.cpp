#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : fixedPoint_(other.fixedPoint_) {
  std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &other) {
  if (this == &other) return *this;
  std::cout << "Assignment operator called" << std::endl;
  this->fixedPoint_ = other.fixedPoint_;
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->fixedPoint_;
}

void Fixed::setRawBits(int const raw) { this->fixedPoint_ = raw; }
