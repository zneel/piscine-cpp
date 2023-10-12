#include "DiamondTrap.hpp"

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("Default_clap_name"),
      ScavTrap("Default_clap_name"),
      FragTrap("Default_clap_name"),
      name_("Default") {
  this->energy_ = 50;
  std::cout << "DiamTrap " << this->name_ << " default constructor called"
            << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"),
      ScavTrap(name + "_clap_name"),
      FragTrap(name + "_clap_name"),
      name_(name) {
  this->energy_ = 50;
  std::cout << "DiamTrap " << this->name_ << " parameter constructor called"
            << std::endl;
  std::cout << "HP: " << this->hp_ << std::endl;
  std::cout << "ENERGY: " << this->energy_ << std::endl;
  std::cout << "ATK: " << this->atk_ << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other)
    : ClapTrap(other.name_ + "_clap_name"),
      ScavTrap(other.name_ + "_clap_name"),
      FragTrap(other.name_ + "_clap_name") {
  this->name_ = other.name_;
  this->hp_ = other.hp_;
  this->energy_ = other.energy_;
  this->atk_ = other.atk_;
  std::cout << "DiamTrap " << this->name_ << " copy constructor called"
            << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other) {
  if (this == &other) return *this;
  ClapTrap::operator=(other);
  ScavTrap::operator=(other);
  FragTrap::operator=(other);
  this->name_ = other.name_;
  this->hp_ = other.hp_;
  this->energy_ = other.energy_;
  this->atk_ = other.atk_;
  std::cout << "DiamTrap " << this->name_ << " assignment operator called"
            << std::endl;
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamTrap " << this->name_ << " destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
  std::cout << "My name is: " << this->name_ << " and my ClapTrap name is "
            << ClapTrap::name_ << std::endl;
}
