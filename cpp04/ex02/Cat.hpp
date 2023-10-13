#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
 public:
  Cat();
  Cat(Cat const &);
  Cat &operator=(Cat const &);
  ~Cat();
  void makeSound() const;

 private:
  Brain *brain_;
};
