#pragma once

#include <iostream>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 public:
  ScavTrap();
  ScavTrap(std::string const name);
  ScavTrap(ScavTrap const &);
  ScavTrap &operator=(ScavTrap const &);
  ~ScavTrap();
  void guardGate();
  void attack(const std::string &target);
};