#include "ClapTrap.hpp"

int main() {
  ClapTrap ct1("CL4P");
  ClapTrap ct2(ct1);
  ClapTrap ct3;
  ct3 = ct1;

  ct1.attack("TR4P");
  ct1.takeDamage(9);
  ct1.beRepaired(10);
  ct1.takeDamage(9);
  ct1.takeDamage(9);
  ct1.beRepaired(9);
  ct1.takeDamage(10);
  ct1.attack("TR4P");

  return 0;
}