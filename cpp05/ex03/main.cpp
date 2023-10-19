#include <exception>
#include <iostream>
#include <sys/types.h>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    {
        try
        {
            Intern someRandomIntern;
            AForm *rrf;
            rrf = someRandomIntern.makeForm("shrubbery_creation", "Bender");
            Bureaucrat b("Bender", 1);
            b.signForm(*rrf);
            b.executeForm(*rrf);
            delete rrf;
            std::cout << "===========================" << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try
        {
            Intern someRandomIntern;
            AForm *rrf;
            rrf = someRandomIntern.makeForm("robotomy_request", "Bender2");
            Bureaucrat b("Bender2", 1);
            b.signForm(*rrf);
            b.executeForm(*rrf);
            delete rrf;
            std::cout << "===========================" << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try
        {
            Intern someRandomIntern;
            AForm *rrf;
            rrf = someRandomIntern.makeForm("presidential_pardon", "Bender3");
            Bureaucrat b("Bender3", 1);
            b.signForm(*rrf);
            b.executeForm(*rrf);
            delete rrf;
            std::cout << "===========================" << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try
        {
            Intern someRandomIntern;
            AForm *rrf;
            rrf = someRandomIntern.makeForm("", "Bender3");
            Bureaucrat b("Bender3", 1);
            b.signForm(*rrf);
            b.executeForm(*rrf);
            delete rrf;
            std::cout << "===========================" << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}
