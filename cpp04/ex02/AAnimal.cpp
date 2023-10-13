#include "AAnimal.hpp"

AAnimal::AAnimal(std::string type) : type(type) {
  std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::~AAnimal() { std::cout << "AAnimal destructor called" << std::endl; }

AAnimal::AAnimal(AAnimal const &other) : type(other.type) {
  std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &rhs) {
  if (this == &rhs) return *this;
  this->type = rhs.type;
  std::cout << "AAnimal assignment operator called" << std::endl;
  return *this;
}

std::string AAnimal::getType() const { return this->type; }
