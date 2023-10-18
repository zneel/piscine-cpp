#pragma once

#include <cstdlib>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  public:
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &);
    void execute(Bureaucrat const &executor) const;

  private:
    std::string target_;
};
