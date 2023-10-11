#include "Fixed.hpp"

/**
 * @brief Construct a new Fixed::Fixed object
 *
 */
Fixed::Fixed() : fixedPoint_(0 * (1 << this->fractionalBits_)) {
  std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief Construct a new Fixed::Fixed from integer
 *
 * @param i
 */
Fixed::Fixed(int const i) : fixedPoint_(i * (1 << this->fractionalBits_)) {
  std::cout << "Integer constructor called" << std::endl;
}

/**
 * @brief Construct a new Fixed::Fixed from floating point
 *
 * @param f
 */
Fixed::Fixed(float const f)
    : fixedPoint_(roundf(f * (1 << this->fractionalBits_))) {
  std::cout << "Float constructor called" << std::endl;
}

/**
 * @brief Copy constructor
 *
 * @param other
 */
Fixed::Fixed(Fixed const &other) : fixedPoint_(other.fixedPoint_) {
  std::cout << "Copy constructor called" << std::endl;
}

/**
 * @brief Overload assignment operator
 *
 * @param other
 * @return Fixed&
 */
Fixed &Fixed::operator=(const Fixed &other) {
  if (this == &other) return *this;
  std::cout << "Copy assignment operator called" << std::endl;
  this->fixedPoint_ = other.fixedPoint_;
  return *this;
}

/**
 * @brief Destructor
 *
 */
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

/**
 * @brief Overload << operator to print the fixed-point value
 *
 * @param os
 * @param fp
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os, Fixed const &fp) {
  os << fp.toFloat();
  return os;
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->fixedPoint_;
}

void Fixed::setRawBits(int const raw) { this->fixedPoint_ = raw; }

/**
 * @brief Convert the fixed-point value to floating point value
 *
 * @return float
 */
float Fixed::toFloat() const {
  return static_cast<float>(this->fixedPoint_) / (1 << this->fractionalBits_);
}

/**
 * @brief Convert the fixed-point value to integer value
 *
 * @return int
 */
int Fixed::toInt() const { return this->fixedPoint_ >> this->fractionalBits_; };
