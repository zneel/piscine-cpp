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

AForm *Intern::createShrubberyForm(std::string target)
{
    std::cout << "Intern creates shrubbery creation" << std::endl;
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyForm(std::string target)
{
    std::cout << "Intern creates robotomy request" << std::endl;
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialForm(std::string target)
{
    std::cout << "Intern creates presidential pardon" << std::endl;
    return new PresidentialPardonForm(target);
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return "Form not found";
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    struct FormMapping
    {
        std::string name;
        FormCreator creator;
    };

    FormMapping formMappings[] = {{"shrubbery_creation", &Intern::createShrubberyForm},
                                  {"robotomy_request", &Intern::createRobotomyForm},
                                  {"presidential_pardon", &Intern::createPresidentialForm}};

    for (size_t i = 0; i < sizeof(formMappings) / sizeof(FormMapping); ++i)
    {
        if (formMappings[i].name == name)
            return (this->*formMappings[i].creator)(target);
    }
    throw Intern::FormNotFoundException();
}
