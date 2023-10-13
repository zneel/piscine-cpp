#pragma once

#include <iostream>
#include <string>

class Brain {
 public:
  Brain();
  Brain(Brain const &);
  Brain &operator=(Brain const &);
  ~Brain();

 private:
  std::string ideas_[100];
};
