#include "FragTrap.hpp"

int main() {
  FragTrap ft1("SC4V");
  FragTrap ft2(ft1);
  FragTrap ft3;
  ft3 = ft1;
  ft3.highFivesGuys();
  ft3.attack("TR4P");
  ft3.beRepaired(1);
  ft3.takeDamage(101);
  ft3.takeDamage(101);
  return 0;
}
