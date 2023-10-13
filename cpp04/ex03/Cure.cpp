#include "Cure.hpp"

#include "AMateria.hpp"

Cure::Cure() : AMateria("cure") {
  std::cout << "Cure default constructor called" << std::endl;
}
Cure::~Cure() { std::cout << "Cure destructor called" << std::endl; }
Cure::Cure(Cure const &other) : AMateria("cure") {
  std::cout << "Copy constructor called" << std::endl;
}
Cure &Cure::operator=(Cure const &rhs) {
  if (this != &rhs) {
    AMateria::operator=(rhs);
  }
  std::cout << "Assignment operator called" << std::endl;
  return *this;
}

AMateria *Cure::clone() { return new Cure(); }
