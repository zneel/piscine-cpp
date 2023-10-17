#include <exception>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat highestRank = Bureaucrat("Highest", 1);
    Bureaucrat justAboveShrubberySign = Bureaucrat("AboveShrubSign", 138);
    Bureaucrat shrubberySignExact = Bureaucrat("ShrubSignExact", 137);
    Bureaucrat justBelowShrubberySign = Bureaucrat("BelowShrubSign", 136);

    try
    {
        ShrubberyCreationForm f1 = ShrubberyCreationForm("shrubbery");
        highestRank.signForm(f1);
        highestRank.executeForm(f1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        ShrubberyCreationForm f1 = ShrubberyCreationForm("shrubbery");
        justAboveShrubberySign.signForm(f1);
        justAboveShrubberySign.executeForm(f1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        ShrubberyCreationForm f1 = ShrubberyCreationForm("shrubbery");
        shrubberySignExact.signForm(f1);
        shrubberySignExact.executeForm(f1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        ShrubberyCreationForm f1 = ShrubberyCreationForm("shrubbery");
        justBelowShrubberySign.signForm(f1);
        justBelowShrubberySign.executeForm(f1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
