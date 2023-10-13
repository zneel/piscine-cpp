#pragma once

#include <iostream>
#include <string>

class Animal {
 public:
  Animal();
  virtual ~Animal();
  Animal(Animal const&);
  Animal& operator=(Animal const&);

  std::string getType() const;
  void setType(std::string type);
  virtual void makeSound() const;

 protected:
  std::string type;

 private:
};
