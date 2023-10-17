#include <exception>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  try {
    Bureaucrat toto = Bureaucrat("Toto", 146);
    ShrubberyCreationForm f1 = ShrubberyCreationForm("test");
    toto.signForm(f1);
    toto.executeForm(f1);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
