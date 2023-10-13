#pragma once

#include "Animal.hpp"

class Dog : public Animal {
 public:
  Dog();
  Dog(Dog const &);
  Dog &operator=(Dog const &);
  ~Dog();
  void makeSound() const;

 protected:
 private:
};
