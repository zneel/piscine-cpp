#include "FragTrap.hpp"

int main() {
  FragTrap ft1("SC4V");
  FragTrap ft2(ft1);
  FragTrap ft3;
  ft3 = ft1;
  ft1.highFivesGuys();
  ft1.attack("TR4P");
  ft1.beRepaired(1);
  ft1.takeDamage(101);
  ft1.takeDamage(101);
  return 0;
}