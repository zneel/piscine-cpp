#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::~AMateria() {}

AMateria::AMateria(AMateria const &other) {}

AMateria &AMateria::operator=(AMateria const &rhs) {}

std::string const &AMateria::getType() const { return this->type; }
