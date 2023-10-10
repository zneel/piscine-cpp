#include "Weapon.hpp"

Weapon::Weapon() {}
Weapon::Weapon(std::string type) : type_(type) {
  std::cout << "Weapon " << this->type_ << " constructor called" << std::endl;
}
Weapon::~Weapon() {
  std::cout << "Weapon " << this->type_ << " destructor called" << std::endl;
}
std::string const& Weapon::getType() const { return this->type_; }
void Weapon::setType(std::string type) { this->type_ = type; }
