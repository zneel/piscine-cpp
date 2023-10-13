#pragma once

#include <iostream>
#include <string>

class WrongAnimal {
 public:
  WrongAnimal(std::string = "Unknown");
  ~WrongAnimal();
  WrongAnimal(WrongAnimal const&);
  WrongAnimal& operator=(WrongAnimal const&);

  std::string getType() const;
  void makeSound() const;

 protected:
  std::string type;
};
