#include "Dog.hpp"

#include "Animal.hpp"

Dog::Dog() : Animal("Dog") {
  std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other) {
  std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &rhs) {
  if (this == &rhs) return *this;
  Animal::operator=(rhs);
  std::cout << "Dog assignment operator called" << std::endl;
  return *this;
}

void Dog::makeSound() const { std::cout << "Dog barks" << std::endl; }

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }
