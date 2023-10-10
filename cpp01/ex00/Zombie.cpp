#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name_(name) {
  std::cout << "Zombie: " << this->name_ << " created" << std::endl;
}
Zombie::~Zombie() {
  std::cout << "Zombie: " << this->name_ << " deleted" << std::endl;
}

void Zombie::announce() {
  std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
