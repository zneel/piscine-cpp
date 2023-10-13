#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  int count = 4;
  Animal *animals[count];

  for (int i = 0; i < count; ++i) {
    if (i % 2)
      animals[i] = new Dog();
    else
      animals[i] = new Cat();
  }
  std::cout << "====================" << std::endl;
  for (int i = 0; i < count; ++i) {
    animals[i]->getType();
    animals[i]->makeSound();
  }
  std::cout << "====================" << std::endl;
  for (int i = 0; i < count; ++i) delete animals[i];
}
