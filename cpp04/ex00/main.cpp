#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  const Animal* meta = new Animal();
  const Animal* dog = new Dog();
  const Animal* cat = new Cat();
  std::cout << dog->getType() << " " << std::endl;
  std::cout << cat->getType() << " " << std::endl;
  cat->makeSound();
  dog->makeSound();
  meta->makeSound();
  delete meta;
  delete dog;
  delete cat;

  const WrongAnimal* wrongCat = new WrongCat();
  wrongCat->makeSound();
  delete wrongCat;
  return 0;
}
