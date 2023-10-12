#include "Animal.hpp"

Animal::Animal() {
  std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

Animal::Animal(Animal const &other) : type(other.type) {}

Animal &Animal::operator=(Animal const &rhs) {
  if (this == &rhs) return *this;
  this->type = rhs.type;
  return *this;
}
