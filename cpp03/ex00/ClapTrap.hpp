#pragma once

#include <iostream>
#include <string>
class ClapTrap {
 public:
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(ClapTrap const &);
  ClapTrap &operator=(ClapTrap const &);
  ~ClapTrap();

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

 private:
  std::string name_;
  int hp_;
  int energy_;
  int atk_;
};
