#pragma once

#include <iostream>
#include <string>

class Weapon {
 public:
  Weapon();
  Weapon(std::string type);
  ~Weapon();
  void setType(std::string type);
  const std::string &getType();

 private:
  std::string type_;
};
