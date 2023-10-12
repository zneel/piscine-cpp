#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  ScavTrap st1("SC4V");
  ScavTrap st2(st1);
  ScavTrap st3;
  st3 = st1;
  st1.guardGate();
  st1.attack("TR4P");
  st1.beRepaired(1);
  st1.takeDamage(101);
  st1.takeDamage(101);
  return 0;
}