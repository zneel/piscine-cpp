#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"
class Ice : public AMateria {
 public:
  Ice();
  ~Ice();
  Ice(Ice const &);
  Ice &operator=(Ice const &);

  AMateria *clone() const;
  void use(ICharacter &);
};
