#include "Dog.hpp"

#include "Animal.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal() {
  std::cout << "Dog constructor called" << std::endl;
  this->setType("Dog");
  this->brain_ = new Brain();
}

Dog::Dog(Dog const &other) : Animal(other) {
  this->brain_ = new Brain(*other.brain_);
  this->setType(other.type);
  std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &rhs) {
  if (this == &rhs) return *this;
  Animal::operator=(rhs);
  this->brain_ = new Brain(*rhs.brain_);
  this->setType(rhs.type);
  std::cout << "Dog assignment operator called" << std::endl;
  return *this;
}

void Dog::makeSound() const { std::cout << "Dog barks" << std::endl; }

Dog::~Dog() {
  delete this->brain_;
  std::cout << "Dog destructor called" << std::endl;
}
