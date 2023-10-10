#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {}
ClapTrap::ClapTrap(std::string name)
    : name_(name), hp_(10), energy_(10), atk_(0){};

ClapTrap::ClapTrap(ClapTrap const &other) { *this = other; }
ClapTrap &ClapTrap::operator=(ClapTrap const &other) {
  if (this == &other) return *this;
  this->name_ = other.name_;
  this->atk_ = other.atk_;
  return *this;
}