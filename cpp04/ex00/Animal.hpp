#pragma once

#include <iostream>
#include <string>

class Animal {
 public:
  Animal(std::string type = "Unknown");
  virtual ~Animal();
  Animal(Animal const&);
  Animal& operator=(Animal const&);

  std::string getType() const;
  virtual void makeSound() const;

 protected:
  std::string type;
};
