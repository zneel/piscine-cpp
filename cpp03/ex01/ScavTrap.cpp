#include "ScavTrap.hpp"

#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("") {
  std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const name) : ClapTrap("ScavTrap") {
  std::cout << "ScavTrap Parameter constructor called" << std::endl;
  this->name_ = name;
  this->hp_ = 100;
  this->energy_ = 50;
  this->atk_ = 20;
  std::cout << "ScavTrap values: " << std::endl;
  std::cout << "name: " << this->name_ << std::endl;
  std::cout << "hp: " << this->hp_ << std::endl;
  std::cout << "energy: " << this->energy_ << std::endl;
  std::cout << "atk: " << this->atk_ << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other) {
  std::cout << "ScavTrap copy constructor called" << std::endl;
  *this = other;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other) {
  if (this == &other) return *this;
  this->hp_ = other.hp_;
  this->name_ = other.name_;
  this->energy_ = other.energy_;
  this->atk_ = other.atk_;
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap is now in gate keeper mode!" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
  if (this->energy_ < 1 || this->hp_ < 1) return;
  std::cout << "ScavTrap " << this->name_ << " attacks " << target
            << ", causing " << this->atk_ << " points of damage!" << std::endl;
  this->energy_--;
}
