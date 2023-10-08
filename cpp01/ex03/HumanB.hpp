#pragma once

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanB {
 public:
  HumanB();
  HumanB(std::string name);
  ~HumanB();
  void attack();
  void setWeapon(Weapon &weapon);

 private:
  std::string name_;
  Weapon *weapon_;
};
