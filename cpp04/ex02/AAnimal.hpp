#pragma once

#include <iostream>
#include <string>

class AAnimal {
 public:
  virtual ~AAnimal();
  AAnimal(AAnimal const&);
  AAnimal& operator=(AAnimal const&);

  std::string getType() const;
  virtual void makeSound() const = 0;

 protected:
  AAnimal(std::string type = "Unknown");
  std::string type;
};
