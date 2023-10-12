#include "ClapTrap.hpp"

// Constructor - Destructor ====================================================
ClapTrap::ClapTrap() : name_("Default"), hp_(10), energy_(10), atk_(0) {
  std::cout << "ClapTrap " << this->name_ << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : name_(name), hp_(10), energy_(10), atk_(0) {
  std::cout << "ClapTrap " << this->name_ << " parameter constructor called"
            << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other)
    : name_(other.name_),
      hp_(other.hp_),
      energy_(other.energy_),
      atk_(other.atk_) {
  std::cout << "ClapTrap " << this->name_ << " copy constructor called"
            << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other) {
  if (this == &other) return *this;
  this->name_ = other.name_;
  this->hp_ = other.hp_;
  this->energy_ = other.energy_;
  this->atk_ = other.atk_;
  std::cout << "ClapTrap " << this->name_ << " assignment constructor called"
            << std::endl;
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << this->name_ << " destructor called" << std::endl;
}

// Member functions ============================================================
/**
 * @brief Attack a target
 *
 * @param target
 */
void ClapTrap::attack(const std::string &target) {
  if (this->energy_ <= 0 || this->hp_ <= 0) {
    std::cout << "ClapTrap " << this->name_ << " is dead or exhausted"
              << std::endl;
    return;
  }
  this->energy_--;
  std::cout << "ClapTrap " << this->name_ << " attacks " << target
            << ", causing " << this->atk_ << " points of damage he has now "
            << this->energy_ << " energy" << std::endl;
}

/**
 * @brief Take damage
 *
 * @param amount
 */
void ClapTrap::takeDamage(unsigned int amount) {
  if (this->hp_ <= 0) {
    std::cout << "ClapTrap " << this->name_ << " is dead" << std::endl;
    return;
  }

  this->hp_ -= amount;
  if (this->hp_ < 0) this->hp_ = 0;
  std::cout << "ClapTrap " << this->name_ << " receive " << amount
            << " points of damage and has now " << this->hp_ << " hit points "
            << std::endl;
}

/**
 * @brief Repair hit points
 *
 * @param amount
 */
void ClapTrap::beRepaired(unsigned int amount) {
  if (this->energy_ <= 0 || this->hp_ <= 0) return;
  this->energy_--;
  this->hp_ += amount;
  std::cout << "ClapTrap " << this->name_ << " repaired for " << amount
            << " hit points. He has now " << this->hp_ << " hit points and "
            << this->energy_ << " energy" << std::endl;
}
