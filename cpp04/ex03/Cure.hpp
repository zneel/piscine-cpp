#pragma once

#include "AMateria.hpp"

class Cure : public AMateria {
 public:
  Cure();
  ~Cure();
  Cure(Cure const &);
  Cure &operator=(Cure const &);

  AMateria *clone() const;
  void use(ICharacter &);
};
