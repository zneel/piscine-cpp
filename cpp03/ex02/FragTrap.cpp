#include "FragTrap.hpp"

#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
  this->name_ = "Default";
  this->hp_ = 100;
  this->energy_ = 100;
  this->atk_ = 30;
  std::cout << "FragTrap " << this->name_ << " default constructor called"
            << std::endl;
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name) {
  this->name_ = name;
  this->hp_ = 100;
  this->energy_ = 100;
  this->atk_ = 30;
  std::cout << "FragTrap " << this->name_ << " parameter constructor called"
            << std::endl;
}

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other) {
  this->name_ = other.name_;
  this->hp_ = other.hp_;
  this->energy_ = other.energy_;
  this->atk_ = other.atk_;
  std::cout << "FragTrap " << this->name_ << " copy constructor called"
            << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other) {
  if (this == &other) return *this;
  this->name_ = other.name_;
  this->hp_ = other.hp_;
  this->energy_ = other.energy_;
  this->atk_ = other.atk_;
  std::cout << "FragTrap " << this->name_
            << " assignement operator constructor called" << std::endl;
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << this->name_ << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap " << this->name_ << " says: HIGH FIVE GUYS!"
            << std::endl;
}
