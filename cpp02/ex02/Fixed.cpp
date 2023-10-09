#include "Fixed.hpp"

#include <cmath>
#include <iostream>
#include <ostream>
#include <sstream>

// Constructors - Destructor

Fixed::Fixed() : fp_(0 * (1 << this->fb_)) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const i) : fp_(i * (1 << this->fb_)) {
  std::cout << "Integer constructor called" << std::endl;
}

Fixed::Fixed(float const f) : fp_(roundf(f * (1 << this->fb_))) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f) {
  std::cout << "Copy constructor called" << std::endl;
  *this = f;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed &Fixed::operator=(const Fixed &other) {
  if (this == &other) return *this;
  std::cout << "Copy assignment operator called" << std::endl;
  this->fp_ = other.getRawBits();
  return *this;
}

// Setters - getters

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->fp_;
}

void Fixed::setRawBits(int const raw) { this->fp_ = raw; }

float Fixed::toFloat() const {
  return static_cast<float>(this->fp_) / (1 << this->fb_);
}

int Fixed::toInt() const { return this->fp_ >> this->fb_; };

// Overloads

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

Fixed &Fixed::operator++() {
  this->fp_ += 1;
  return *this;
}

Fixed &Fixed::operator--() {
  this->fp_ -= 1;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp = *this;
  this->fp_ += 1;
  return tmp;
}

Fixed Fixed::operator--(int) {
  Fixed tmp = *this;
  this->fp_ -= 1;
  return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return a > b ? b : a; }
Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
  return a > b ? b : a;
}
Fixed &Fixed::max(Fixed &a, Fixed &b) { return a > b ? a : b; }
Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
  return a > b ? a : b;
}

std::ostream &operator<<(std::ostream &os, Fixed const &fp) {
  os << fp.toFloat();
  return os;
}
