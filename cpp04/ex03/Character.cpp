#include "Character.hpp"

Character::Character(std::string name) : name_(name) {
  for (int i = 0; i < 4; ++i) this->inventory_[i] = 0;
  std::cout << "Character default constructor called" << std::endl;
}

Character::~Character() {
  for (int i = 0; i < 4; ++i) {
    delete this->inventory_[i];
  }
  std::cout << "Character destructor called" << std::endl;
}

Character::Character(Character const &other) : name_(other.name_) {
  for (int i = 0; i < 4; ++i) this->inventory_[i] = other.inventory_[i];
  std::cout << "Character copy constructor called" << std::endl;
}

Character &Character::operator=(Character const &rhs) {
  if (this != &rhs) {
    this->name_ = rhs.getName();
    for (int i = 0; i < 4; ++i) this->inventory_[i] = rhs.inventory_[i];
  }
  std::cout << "Character assignment operator called" << std::endl;
  return *this;
}

std::string const &Character::getName() const { return this->name_; }

void Character::equip(AMateria *m) {
  for (int i = 0; i < 4; ++i) {
    if (this->inventory_[i] == 0) {
      this->inventory_[i] = m;
      std::cout << "Equiped in slot: " << i << std::endl;
      return;
    }
  }

  std::cout << "Equipment full" << std::endl;
}

void Character::unequip(int idx) {
  if (idx < 0 || idx > 3) {
    std::cout << "Wrong index to unequip, should be 0-3" << std::endl;
    return;
  };

  this->inventory_[idx] = 0;
}

void Character::use(int idx, ICharacter &target) {
  if (idx < 0 || idx > 3) {
    std::cout << "Wrong index to use, should be 0-3" << std::endl;
    return;
  };

  this->inventory_[idx]->use(target);
}
