#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
  WrongCat();
  WrongCat(WrongCat const &);
  WrongCat &operator=(WrongCat const &);
  ~WrongCat();

  void makeSound() const;
};
