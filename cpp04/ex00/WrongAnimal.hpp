#pragma once

#include <iostream>
#include <string>

class WrongAnimal {
 public:
  WrongAnimal();
  ~WrongAnimal();
  WrongAnimal(WrongAnimal const&);
  WrongAnimal& operator=(WrongAnimal const&);

  std::string getType() const;
  void setType(std::string type);
  void makeSound() const;

 protected:
  std::string type;

 private:
};
