#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat toto = Bureaucrat("Toto", 1);
        Form f1 = Form("42 signup", 1, 1);
        toto.signForm(f1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "=======================" << std::endl;
    try
    {
        Bureaucrat toto = Bureaucrat("Toto", 2);
        Form f1 = Form("42 signup", 1, 1);
        toto.signForm(f1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "=======================" << std::endl;
    try
    {
        Bureaucrat toto = Bureaucrat("Toto", 2);
        Form f1 = Form("Noob coalition", 150, 1);
        toto.signForm(f1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "=======================" << std::endl;
    try
    {
        Bureaucrat toto = Bureaucrat("Toto", 1);
        Form f1 = Form("Noob coalition", 151, 1);
        toto.signForm(f1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "=======================" << std::endl;
    try
    {
        Bureaucrat toto = Bureaucrat("Toto", 1);
        Form f1 = Form("Noob coalition", 0, 1);
        toto.signForm(f1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
