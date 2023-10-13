#include "Cat.hpp"

#include "Animal.hpp"

Cat::Cat() : Animal("Cat") {
  std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat const &other) : Animal(other) {
  std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &rhs) {
  if (this == &rhs) return *this;
  Animal::operator=(rhs);
  std::cout << "Cat assignment operator called" << std::endl;
  return *this;
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

void Cat::makeSound() const { std::cout << "Cat makes miaw" << std::endl; }
