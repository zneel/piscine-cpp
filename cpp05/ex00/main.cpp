#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat ok("Toto", 150);
        std::cout << ok << std::endl;
        ++ok;
        std::cout << ok << std::endl;
        --ok;
        std::cout << ok << std::endl;
        --ok;
    }
    catch (std::exception &e)
    {
        std::cout << "Toto ";
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat noklow("Tata", 151);
        std::cout << noklow << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Tata ";
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat nokhigh("Titi", 0);
        std::cout << nokhigh << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Titi ";
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat ok2("Tutu", 1);
        std::cout << ok2 << std::endl;
        --ok2;
        std::cout << ok2 << std::endl;
        ++ok2;
        std::cout << ok2 << std::endl;
        ++ok2;
    }
    catch (std::exception &e)
    {
        std::cout << "Tutu ";
        std::cout << e.what() << std::endl;
    }
    return 0;
}
