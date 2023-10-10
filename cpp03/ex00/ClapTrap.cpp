#include "ClapTrap.hpp"

ClapTrap::ClapTrap() { std::cout << "Default constructor called" << std::endl; }
ClapTrap::ClapTrap(std::string name)
    : name_(name), hp_(10), energy_(10), atk_(0) {
  std::cout << "Param constructor called" << std::endl;
};

ClapTrap::ClapTrap(ClapTrap const &other) {
  *this = other;
  std::cout << "Copy constructor called" << std::endl;
}
ClapTrap &ClapTrap::operator=(ClapTrap const &other) {
  std::cout << "Assignment constructor called" << std::endl;
  if (this == &other) return *this;
  this->name_ = other.name_;
  this->atk_ = other.atk_;
  return *this;
}

void ClapTrap::attack(const std::string &target) {
  if (this->energy_ < 1) return;
  std::cout << "ClapTrap " << this->name_
            << " attacks <target>, causing <damage> points of damage!"
}
void ClapTrap::takeDamage(unsigned int amount) {}
void ClapTrap::beRepaired(unsigned int amount) {}
