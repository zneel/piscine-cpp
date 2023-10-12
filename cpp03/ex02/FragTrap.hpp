#pragma once

#include <iostream>

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
 public:
  FragTrap();
  FragTrap(std::string const name);
  FragTrap(FragTrap const &);
  FragTrap &operator=(FragTrap const &);
  ~FragTrap();
  void highFivesGuys(void);
};
