#include "Dog.hpp"

#include "Animal.hpp"

Dog::Dog() : Animal("Dog"), brain_(new Brain()) {
  std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other), brain_(new Brain(*other.brain_)) {
  std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &rhs) {
  if (this != &rhs) {
    Animal::operator=(rhs);
    delete this->brain_;
    this->brain_ = new Brain(*rhs.brain_);
  }
  std::cout << "Dog assignment operator called" << std::endl;
  return *this;
}

void Dog::makeSound() const { std::cout << "Dog barks" << std::endl; }
void Dog::getBrainAddr() const {
  std::cout << "Brain address: " << &this->brain_ << std::endl;
}
Dog::~Dog() {
  delete this->brain_;
  std::cout << "Dog destructor called" << std::endl;
}
