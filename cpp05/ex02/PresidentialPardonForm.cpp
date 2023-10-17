#include "PresidentialPardonForm.hpp"

#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5), target_(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
    : AForm(other.getName(), other.getGradeRequiredToSign(), other.getGradeRequiredToExec()), target_(other.target_)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
    if (this != &rhs)
    {
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!getSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() >= getGradeRequiredToExec())
        throw AForm::GradeTooLowException();
    std::cout << target_ << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
