#pragma once

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
 public:
  DiamondTrap();
  DiamondTrap(std::string name);
  DiamondTrap(DiamondTrap const &);
  DiamondTrap &operator=(DiamondTrap const &);
  ~DiamondTrap();
  void whoAmI();
  using ScavTrap::attack;

 private:
  std::string name_;
};
