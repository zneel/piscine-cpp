#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>
class Intern
{
  public:
    Intern();
    ~Intern();
    Intern(Intern const &);
    Intern &operator=(Intern const &);
    AForm *makeForm(std::string name, std::string target);
};
