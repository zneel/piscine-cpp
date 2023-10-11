#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint_(0 * (1 << this->fractionalBits_)) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const i) : fixedPoint_(i * (1 << this->fractionalBits_)) {
  std::cout << "Integer constructor called" << std::endl;
}

Fixed::Fixed(float const f)
    : fixedPoint_(roundf(f * (1 << this->fractionalBits_))) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other) : fixedPoint_(other.getRawBits()) {
  std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
  if (this == &other) return *this;
  std::cout << "Copy assignment operator called" << std::endl;
  this->fixedPoint_ = other.getRawBits();
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

std::ostream &operator<<(std::ostream &os, Fixed const &fp) {
  os << fp.toFloat();
  return os;
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->fixedPoint_;
}

void Fixed::setRawBits(int const raw) { this->fixedPoint_ = raw; }

float Fixed::toFloat() const {
  return static_cast<float>(this->fixedPoint_) / (1 << this->fractionalBits_);
}

int Fixed::toInt() const { return this->fixedPoint_ >> this->fractionalBits_; };
