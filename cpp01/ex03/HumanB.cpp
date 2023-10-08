#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
  this->name_ = name;
  std::cout << "HumanB " << name << " with weapon <"
            << "> constructor called" << std::endl;
}

HumanB::~HumanB() { std::cout << "HumanB destructor called" << std::endl; }
void HumanB::attack() {
  if (this->weapon_) {
    std::cout << this->name_ << " attacks with their "
              << this->weapon_->getType() << std::endl;
  }
}

void HumanB::setWeapon(Weapon &weapon) { this->weapon_ = &weapon; }
