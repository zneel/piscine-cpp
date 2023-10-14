#include "Cure.hpp"

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {
  std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure() { std::cout << "Cure destructor called" << std::endl; }

Cure::Cure(Cure const &other) : AMateria("cure") {
  (void)other;
  std::cout << "Copy constructor called" << std::endl;
}

Cure &Cure::operator=(Cure const &rhs) {
  if (this != &rhs) {
    AMateria::operator=(rhs);
  }
  std::cout << "Assignment operator called" << std::endl;
  return *this;
}

AMateria *Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
