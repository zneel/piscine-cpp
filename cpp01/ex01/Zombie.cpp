#include "Zombie.hpp"

Zombie::Zombie() { std::cout << "Zombie created" << std::endl; }
Zombie::~Zombie() { std::cout << "Zombie deleted" << std::endl; }

void Zombie::setName(std::string name) { this->name_ = name; }
void Zombie::announce() {
  std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
