#include "ScavTrap.hpp"

#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
  this->name_ = "Default";
  this->hp_ = 100;
  this->energy_ = 50;
  this->atk_ = 20;
  std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name) {
  this->name_ = name;
  this->hp_ = 100;
  this->energy_ = 50;
  this->atk_ = 20;
  std::cout << "ScavTrap " << this->name_ << " parameter constructor called"
            << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other) {
  this->name_ = other.name_;
  this->hp_ = other.hp_;
  this->energy_ = other.energy_;
  this->atk_ = other.atk_;
  std::cout << "ScavTrap " << this->name_ << " copy constructor called"
            << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other) {
  if (this == &other) return *this;
  this->name_ = other.name_;
  this->hp_ = other.hp_;
  this->energy_ = other.energy_;
  this->atk_ = other.atk_;
  std::cout << "ScavTrap " << this->name_ << " assignment operator called"
            << std::endl;
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << this->name_ << " destructor called" << std::endl;
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << this->name_ << " is now in gate keeper mode!"
            << std::endl;
}

void ScavTrap::attack(const std::string &target) {
  if (this->energy_ <= 0 || this->hp_ <= 0) {
    std::cout << "ScavTrap " << this->name_ << " is dead or exhausted"
              << std::endl;
    return;
  }
  this->energy_--;
  std::cout << "ScavTrap " << this->name_ << " attacks " << target
            << ", causing " << this->atk_ << " points of damage he has now "
            << this->energy_ << " energy" << std::endl;
}
