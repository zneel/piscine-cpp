#include "DiamondTrap.hpp"

int main() {
  DiamondTrap dt1("DI4M");
  DiamondTrap dt2(dt1);
  DiamondTrap dt3;
  dt3 = dt1;
  dt3.highFivesGuys();
  dt3.attack("TR4P");
  dt1.whoAmI();
  dt2.whoAmI();
  dt3.whoAmI();
  dt3.guardGate();
  dt3.beRepaired(1);
  dt3.takeDamage(101);
  dt3.takeDamage(101);
  return 0;
}
