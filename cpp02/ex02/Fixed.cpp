#include "Fixed.hpp"

#include <cmath>
#include <iostream>
#include <ostream>
#include <sstream>

// Constructors - Destructor

Fixed::Fixed() : fixedPoint_(0 * (1 << this->fractionalBits_)) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const i) : fixedPoint_(i * (1 << this->fractionalBits_)) {
  std::cout << "Integer constructor called with argument " << i << std::endl;
}

Fixed::Fixed(float const f)
    : fixedPoint_(roundf(f * (1 << this->fractionalBits_))) {
  std::cout << "Float constructor called with argument " << f << std::endl;
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

// Setters - getters

int Fixed::getRawBits() const { return this->fixedPoint_; }

void Fixed::setRawBits(int const raw) { this->fixedPoint_ = raw; }

float Fixed::toFloat() const {
  return static_cast<float>(this->fixedPoint_) / (1 << this->fractionalBits_);
}

int Fixed::toInt() const { return this->fixedPoint_ >> this->fractionalBits_; };

// Comparison overloads

bool Fixed::operator>(Fixed const &fp) const {
  return this->getRawBits() > fp.getRawBits();
}

bool Fixed::operator<(Fixed const &fp) const {
  return this->getRawBits() < fp.getRawBits();
}

bool Fixed::operator>=(Fixed const &fp) const {
  return this->getRawBits() >= fp.getRawBits();
}

bool Fixed::operator<=(Fixed const &fp) const {
  return this->getRawBits() <= fp.getRawBits();
}

bool Fixed::operator==(Fixed const &fp) const {
  return this->getRawBits() == fp.getRawBits();
}

bool Fixed::operator!=(Fixed const &fp) const {
  return this->getRawBits() != fp.getRawBits();
}

// Arithmetics overloads

Fixed Fixed::operator+(Fixed const &fp) {
  return this->toFloat() + fp.toFloat();
}

Fixed Fixed::operator-(Fixed const &fp) {
  return this->toFloat() - fp.toFloat();
}

Fixed Fixed::operator*(Fixed const &fp) {
  return this->toFloat() * fp.toFloat();
}

Fixed Fixed::operator/(Fixed const &fp) {
  return this->toFloat() / fp.toFloat();
}

// Increment - decrement operators

// Prefix
Fixed &Fixed::operator++() {
  this->fixedPoint_ += 1;
  return *this;
}

Fixed &Fixed::operator--() {
  this->fixedPoint_ -= 1;
  return *this;
}

// Postfix
Fixed Fixed::operator++(int) {
  Fixed tmp = *this;
  this->fixedPoint_ += 1;
  return tmp;
}
Fixed Fixed::operator--(int) {
  Fixed tmp = *this;
  this->fixedPoint_ -= 1;
  return tmp;
}

// Min - Max functions
Fixed &Fixed::min(Fixed &a, Fixed &b) { return a > b ? b : a; }
Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
  return a > b ? b : a;
}
Fixed &Fixed::max(Fixed &a, Fixed &b) { return a > b ? a : b; }
Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
  return a > b ? a : b;
}

// Output stream operator
std::ostream &operator<<(std::ostream &os, Fixed const &fp) {
  os << fp.toFloat();
  return os;
}
