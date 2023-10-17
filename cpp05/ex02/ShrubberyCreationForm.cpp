#include "ShrubberyCreationForm.hpp"

#include "AForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137), target_(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
    : AForm(other.getName(), other.getGradeRequiredToSign(), other.getGradeRequiredToExec())
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    if (this != &rhs)
    {
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() >= getGradeRequiredToExec())
        throw AForm::GradeTooLowException();
    std::string tree_;
    tree_ += "\n";
    tree_ += "                   ,@@@@@@@,\n";
    tree_ += "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
    tree_ += "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
    tree_ += "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
    tree_ += "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
    tree_ += "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
    tree_ += "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
    tree_ += "       |o|        | |         | |\n";
    tree_ += "       |.|        | |         | |\n";
    tree_ += "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";

    std::ofstream file;
    std::string outfile = target_ + "_shrubbery";
    file.open(outfile.c_str(), std::ios_base::out);
    if (file.is_open())
    {
        file << tree_;
        file.close();
    }
    else
    {
        std::cout << std::strerror(errno) << std::endl;
    }
}
