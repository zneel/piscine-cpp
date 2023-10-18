#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}
Intern::~Intern()
{
}
Intern::Intern(Intern const &other)
{
    (void)other;
}
Intern &Intern::operator=(Intern const &rhs)
{
    (void)rhs;
    return *this;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int i = 0;
    while (i < 3 && name != forms[i])
        i++;
    switch (i)
    {
    case 0:
        std::cout << "Intern creates " << name << std::endl;
        return new ShrubberyCreationForm(target);
    case 1:
        std::cout << "Intern creates " << name << std::endl;
        return new RobotomyRequestForm(target);
    case 2:
        std::cout << "Intern creates " << name << std::endl;
        return new PresidentialPardonForm(target);
    default:
        std::cout << "Intern doesn't know this form" << std::endl;
        break;
    }
    return NULL;
}
