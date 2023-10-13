#include "Cat.hpp"

#include "Animal.hpp"

Cat::Cat() : Animal() {
  std::cout << "Cat constructor called" << std::endl;
  this->setType("Cat");
}

Cat::Cat(Cat const &other) : Animal(other) {
  std::cout << "Cat copy constructor called" << std::endl;
  this->setType(other.type);
}

Cat &Cat::operator=(Cat const &rhs) {
  if (this == &rhs) return *this;
  Animal::operator=(rhs);
  this->setType(rhs.type);
  std::cout << "Cat assignment operator called" << std::endl;
  return *this;
}

void Cat::makeSound() const { std::cout << "Cat makes miaw" << std::endl; }

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }
