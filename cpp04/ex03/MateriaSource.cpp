#include "MateriaSource.hpp"

#include "AMateria.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; ++i) this->materias_[i] = 0;
  std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; ++i) delete this->materias_[i];
  std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &o) {
  for (int i = 0; i < 4; ++i) {
    this->materias_[i] = o.materias_[i] ? o.materias_[i]->clone() : 0;
  }
  std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs) {
  if (this != &rhs) {
    for (int i = 0; i < 4; ++i) {
      this->materias_[i] = rhs.materias_[i] ? rhs.materias_[i]->clone() : 0;
    }
  }
  std::cout << "MateriaSource assignment operator called" << std::endl;
  return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
  for (int i = 0; i < 4; ++i) {
    if (this->materias_[i] == 0) {
      this->materias_[i] = m;
      std::cout << "Learnt materia: " << m->getType() << std::endl;
      return;
    }
  }

  std::cout << "Cannot learn more materia" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  for (int i = 0; i < 4; ++i) {
    if (this->materias_[i] && this->materias_[i]->getType() == type) {
      std::cout << "Created materia: " << this->materias_[i]->getType()
                << std::endl;
      return this->materias_[i]->clone();
    }
  }
  std::cout << "No materia found for type: " << type << std::endl;
  return 0;
}
