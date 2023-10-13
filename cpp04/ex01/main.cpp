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
  std::cout << "====================" << std::endl;
  // copy constructor
  Dog dog1;
  Dog dog2 = dog1;
  std::cout << "====================" << std::endl;
  dog1.getBrainAddr();
  dog2.getBrainAddr();
  std::cout << "====================" << std::endl;
  // assignment operator
  Dog dog3;
  Dog dog4;
  dog3 = dog4;
  std::cout << "====================" << std::endl;
  dog3.getBrainAddr();
  dog4.getBrainAddr();
  std::cout << "====================" << std::endl;
}
