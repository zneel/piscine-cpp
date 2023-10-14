#pragma once

#include <iostream>
#include <string>

class ICharacter;

class AMateria {
 public:
  AMateria(std::string const &type);
  virtual ~AMateria();
  AMateria(AMateria const &);
  AMateria &operator=(AMateria const &);

  std::string const &getType() const;
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);

 protected:
  AMateria();
  std::string const type;
};
