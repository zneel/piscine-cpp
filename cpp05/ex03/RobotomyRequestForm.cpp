#include "RobotomyRequestForm.hpp"

#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45), target_(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other.getName(), other.getGradeRequiredToSign(), other.getGradeRequiredToExec())
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    if (this != &rhs)
    {
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!getSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() >= getGradeRequiredToExec())
        throw AForm::GradeTooLowException();
    srand(static_cast<unsigned int>(time(0)));
    std::cout << "* drilling noises *" << std::endl;
    if (std::rand() < RAND_MAX / 2)
        std::cout << target_ << " has been robotomized successfully" << std::endl;
    else
        std::cout << target_ << " robotomization failed" << std::endl;
}
