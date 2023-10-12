#include "ClapTrap.hpp"

int main() {
  ClapTrap ct1("CL4P");
  ClapTrap ct2(ct1);
  ClapTrap ct3;
  ct3 = ct1;

  ct3.attack("TR4P");
  ct3.takeDamage(9);
  ct3.beRepaired(10);
  ct3.takeDamage(9);
  ct3.takeDamage(9);
  ct3.beRepaired(9);
  ct3.takeDamage(10);
  ct3.attack("TR4P");

  return 0;
}
