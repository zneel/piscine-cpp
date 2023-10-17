#pragma once

#include <cerrno>
#include <cstring>
#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
  public:
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(ShrubberyCreationForm const &);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &);

    void execute(Bureaucrat const &executor) const;

  private:
    std::string target_;
};
