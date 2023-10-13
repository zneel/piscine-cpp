#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
 public:
  Dog();
  Dog(Dog const &);
  Dog &operator=(Dog const &);
  ~Dog();
  void makeSound() const;
  void getBrainAddr() const;

 private:
  Brain *brain_;
};
