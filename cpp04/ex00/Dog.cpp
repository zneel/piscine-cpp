#include "Dog.hpp"

#include "Animal.hpp"

Dog::Dog() : Animal() {
  std::cout << "Dog constructor called" << std::endl;
  this->setType("Dog");
}

Dog::Dog(Dog const &other) : Animal(other) {
  std::cout << "Dog copy constructor called" << std::endl;
  this->setType(other.type);
}

Dog &Dog::operator=(Dog const &rhs) {
  if (this == &rhs) return *this;
  Animal::operator=(rhs);
  this->setType(rhs.type);

  std::cout << "Dog assignment operator called" << std::endl;
  return *this;
}

void Dog::makeSound() const { std::cout << "Dog barks" << std::endl; }

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }
