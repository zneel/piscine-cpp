#include "Brain.hpp"

Brain::Brain() { std::cout << "Brain constructor called" << std::endl; }

Brain::Brain(Brain const &other) {
  for (int i = 0; i < 100; ++i) this->ideas_[i] = other.ideas_[i];
  std::cout << "Brain copy contructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &rhs) {
  if (this == &rhs) return *this;
  for (int i = 0; i < 100; ++i) this->ideas_[i] = rhs.ideas_[i];
  std::cout << "Brain assignment operator called" << std::endl;
  return *this;
}

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }
