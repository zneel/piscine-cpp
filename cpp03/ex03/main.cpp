#include "DiamondTrap.hpp"

int main() {
  DiamondTrap dt1("DI4M");
  DiamondTrap dt2(dt1);
  DiamondTrap dt3;
  dt3 = dt1;
  dt1.highFivesGuys();
  dt1.attack("TR4P");
  dt1.beRepaired(1);
  dt1.takeDamage(101);
  dt1.takeDamage(101);
  return 0;
}