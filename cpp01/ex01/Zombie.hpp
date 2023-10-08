#pragma once

#include <iostream>
#include <string>

class Zombie {
 public:
  Zombie();
  ~Zombie();
  void announce();
  void setName(std::string name);

 private:
  std::string name_;
};
