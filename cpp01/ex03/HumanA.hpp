#pragma once

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanA {
 public:
  HumanA();
  HumanA(std::string name, Weapon &weapon);
  ~HumanA();
  void attack();

 private:
  std::string name_;
  Weapon &weapon_;
};
