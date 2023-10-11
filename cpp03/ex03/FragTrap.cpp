#include "FragTrap.hpp"

#include "ClapTrap.hpp"

FragTrap::FragTrap() {
  std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name) {
  this->name_ = name;
  this->hp_ = 100;
  this->energy_ = 100;
  this->atk_ = 30;
  std::cout << "FragTrap parameter constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &other) {
  std::cout << "FragTrap copy constructor called" << std::endl;
  *this = other;
}

FragTrap &FragTrap::operator=(FragTrap const &other) {
  if (this == &other) return *this;
  this->name_ = other.name_;
  this->hp_ = other.hp_;
  this->energy_ = other.energy_;
  this->atk_ = other.atk_;
  std::cout << "FragTrap assignement operator constructor called" << std::endl;
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap HIGH FIVE GUYS!" << std::endl;
}
