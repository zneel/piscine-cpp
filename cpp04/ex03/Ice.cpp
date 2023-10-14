#include "Ice.hpp"

#include <iostream>

#include "AMateria.hpp"

Ice::Ice() : AMateria("ice") {
  std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice() { std::cout << "Ice destructor called" << std::endl; }

Ice::Ice(Ice const &other) : AMateria(other.getType()) {
  std::cout << "Copy constructor called" << std::endl;
}

Ice &Ice::operator=(Ice const &rhs) {
  if (this != &rhs) {
    AMateria::operator=(rhs);
  }
  std::cout << "Assignment operator called" << std::endl;
  return *this;
}

AMateria *Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
