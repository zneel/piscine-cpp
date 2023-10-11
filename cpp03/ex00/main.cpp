#include "ClapTrap.hpp"

int main() {
  ClapTrap ct1("CL4P");

  ct1.attack("TR4P");
  ct1.takeDamage(9);
  ct1.beRepaired(9);
  ct1.takeDamage(10);
  ct1.beRepaired(10);
  ct1.attack("TR4P");
  // Attack 10times -> no energy left
  ClapTrap ct2("TR4P");
  ct2.attack("TR4P");
  ct2.attack("TR4P");
  ct2.attack("TR4P");
  ct2.attack("TR4P");
  ct2.attack("TR4P");
  ct2.attack("TR4P");
  ct2.attack("TR4P");
  ct2.attack("TR4P");
  ct2.attack("TR4P");
  ct2.beRepaired(10);
  ct2.attack("TR4P");

  return 0;
}