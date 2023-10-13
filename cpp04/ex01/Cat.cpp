#include "Cat.hpp"

#include "Animal.hpp"

Cat::Cat() : Animal() {
  std::cout << "Cat constructor called" << std::endl;
  this->setType("Cat");
  this->brain_ = new Brain();
}

Cat::Cat(Cat const &other) : Animal(other) {
  this->setType(other.type);
  this->brain_ = new Brain(*other.brain_);
  std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &rhs) {
  if (this == &rhs) return *this;
  Animal::operator=(rhs);
  this->setType(rhs.type);
  this->brain_ = new Brain(*rhs.brain_);
  std::cout << "Cat assignment operator called" << std::endl;
  return *this;
}

void Cat::makeSound() const { std::cout << "Cat makes miaw" << std::endl; }

Cat::~Cat() {
  delete this->brain_;
  std::cout << "Cat destructor called" << std::endl;
}
