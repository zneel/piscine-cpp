#include "AMateria.hpp"

#include "ICharacter.hpp"

AMateria::AMateria(std::string const &type) : type(type) {
  std::cout << "AMateria constructor called" << std::endl;
}

AMateria::~AMateria() {
  std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(AMateria const &other) {
  *this = other;
  std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &rhs) {
  if (this != &rhs) {
  }
  std::cout << "AMateria assignment operator called" << std::endl;
  return *this;
}

std::string const &AMateria::getType() const { return this->type; }

AMateria *AMateria::clone() const {
  std::cout << "AMateria abstract class" << std::endl;
  return 0;
};

void AMateria::use(ICharacter &target) {
  (void)target;
  std::cout << "AMateria abstract class" << std::endl;
};
