#pragma once

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
class MateriaSource : public IMateriaSource {
 public:
  MateriaSource();
  ~MateriaSource();
  MateriaSource(MateriaSource const &);
  MateriaSource &operator=(MateriaSource const &);

  void learnMateria(AMateria *);
  AMateria *createMateria(std::string const &type);

 private:
  AMateria *materias_[4];
};
