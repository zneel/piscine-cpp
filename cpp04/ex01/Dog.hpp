#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
 public:
  Dog();
  Dog(Dog const &);
  Dog &operator=(Dog const &);
  ~Dog();
  void makeSound() const;

 private:
  Brain *brain_;
};
