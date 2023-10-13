#include "Animal.hpp"

Animal::Animal() {
  this->type = "Unknown";
  std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

Animal::Animal(Animal const &other) : type(other.type) {
  std::cout << "Animal copy constructor called" << std::endl;
}

std::string Animal::getType() const { return this->type; }

void Animal::setType(std::string type) { this->type = type; }

void Animal::makeSound() const {
  std::cout << "Animal don't make sound" << std::endl;
}

Animal &Animal::operator=(Animal const &rhs) {
  if (this == &rhs) return *this;
  this->type = rhs.type;
  std::cout << "Animal assignment operator called" << std::endl;
  return *this;
}
