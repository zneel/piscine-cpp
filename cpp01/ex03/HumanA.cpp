#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
    : name_(name), weapon_(weapon) {
  std::cout << "HumanA " << name << " with weapon <" << this->weapon_.getType()
            << "> constructor called" << std::endl;
}

HumanA::~HumanA() { std::cout << "HumanA destructor called" << std::endl; }

void HumanA::attack() {
  std::cout << this->name_ << " attacks with their " << this->weapon_.getType()
            << std::endl;
}
