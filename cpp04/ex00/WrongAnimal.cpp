#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string type) : type(type) {
  std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other) : type(other.type) {
  std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs) {
  if (this == &rhs) return *this;
  this->type = rhs.type;
  std::cout << "WrongAnimal assignment operator called" << std::endl;
  return *this;
}

std::string WrongAnimal::getType() const { return this->type; }

void WrongAnimal::makeSound() const {
  std::cout << "WrongAnimal don't make sound" << std::endl;
}
