#include "WrongCat.hpp"

#include "WrongAnimal.hpp"

WrongCat::WrongCat() : WrongAnimal() {
  std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other) {
  std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs) {
  if (this == &rhs) return *this;
  WrongAnimal::operator=(rhs);
  std::cout << "WrongCat assignment operator called" << std::endl;
  return *this;
}

void WrongCat::makeSound() const {
  std::cout << "WrongCat makes miaw" << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor called" << std::endl;
}
