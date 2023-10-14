#pragma once

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
 public:
  Character(std::string name = "Unknown");
  ~Character();
  Character(Character const &);
  Character &operator=(Character const &);

  std::string const &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);

 private:
  std::string name_;
  AMateria *inventory_[4];
};
