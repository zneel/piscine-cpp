#include "Cat.hpp"

#include "Animal.hpp"

Cat::Cat() : Animal("Cat"), brain_(new Brain()) {
  std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat const &other) : Animal(other), brain_(new Brain(*other.brain_)) {
  std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &rhs) {
  if (this != &rhs) {
    Animal::operator=(rhs);
    delete this->brain_;
    this->brain_ = new Brain(*rhs.brain_);
    std::cout << "Cat assignment operator called" << std::endl;
  }
  return *this;
}

Cat::~Cat() {
  delete this->brain_;
  std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const { std::cout << "Cat makes miaw" << std::endl; }
