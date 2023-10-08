#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
  std::cout << "Allocating on heap" << std::endl;
  Zombie* carl = newZombie("Carl");
  carl->announce();
  delete carl;
  std::cout << "=======================" << std::endl;
  std::cout << "Allocating on stack" << std::endl;
  randomChump("Toto");
  std::cout << "=======================" << std::endl;
}
