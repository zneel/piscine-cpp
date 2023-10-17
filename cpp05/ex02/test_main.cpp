#include <iostream>

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  try {
    // Create a bureaucrat with a grade of 146
    Bureaucrat toto = Bureaucrat("Toto", 146);

    // Create a ShrubberyCreationForm with a target of "test"
    ShrubberyCreationForm f1 = ShrubberyCreationForm("test");

    // Try to sign the form with the bureaucrat
    toto.signForm(f1);

    // Try to execute the form with the bureaucrat
    toto.executeForm(f1);

    // Create a bureaucrat with a grade of 146
    Bureaucrat tata = Bureaucrat("Tata", 146);

    // Create a RobotomyRequestForm with a target of "test"
    RobotomyRequestForm f2 = RobotomyRequestForm("test");

    // Try to sign the form with the bureaucrat
    tata.signForm(f2);

    // Try to execute the form with the bureaucrat
    tata.executeForm(f2);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
