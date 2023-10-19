#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <string>

class Intern
{
  public:
    Intern();
    ~Intern();
    Intern(Intern const &);
    Intern &operator=(Intern const &);
    AForm *makeForm(std::string name, std::string target);

  private:
    class FormNotFoundException : public std::exception
    {
        virtual const char *what() const throw();
    };

    typedef AForm *(Intern::*FormCreator)(std::string target);
    AForm *createShrubberyForm(std::string target);
    AForm *createRobotomyForm(std::string target);
    AForm *createPresidentialForm(std::string target);
};
