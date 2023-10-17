#pragma once

#include <cstdlib>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
  public:
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &);
    void execute(Bureaucrat const &executor) const;

  private:
    std::string target_;
};
