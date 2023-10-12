#pragma once

#include <iostream>
#include <string>

class Animal {
 public:
  Animal();
  ~Animal();
  Animal(Animal const&);
  Animal& operator=(Animal const&);

 protected:
  std::string type;

 private:
};
