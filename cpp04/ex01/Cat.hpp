#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 public:
  Cat();
  Cat(Cat const &);
  Cat &operator=(Cat const &);
  ~Cat();
  void makeSound() const;

 private:
  Brain *brain_;
};
