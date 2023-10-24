#include "RPN.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./rpn [expr]" << std::endl;
        return 1;
    }
    RPN calc;
    try
    {
        std::cout << calc.evaluate(av[1]) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
