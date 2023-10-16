#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"

int main() {
  try {
    Bureaucrat bu("Toto", 150);
    std::cout << bu << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
