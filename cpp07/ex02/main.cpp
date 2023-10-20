#include "Array.hpp"
#include <exception>
#include <iostream>
#include <sstream>

int main()
{
    std::cout << "-------------------Testing with array of ints-------------------" << std::endl;
    Array<int> intArray(15);
    for (unsigned int i = 0; i < intArray.size(); ++i)
        intArray[i] = i + 1;
    for (unsigned int i = 0; i < intArray.size(); ++i)
        std::cout << intArray[i] << std::endl;
    std::cout << "-------------------Testing with array of complex type std::string-------------------" << std::endl;
    Array<std::string> strArray(15);
    for (unsigned int i = 0; i < strArray.size(); ++i)
    {
        std::ostringstream oss;
        oss << "string " << i + 1;
        strArray[i] = oss.str();
    }
    for (unsigned int i = 0; i < strArray.size(); ++i)
        std::cout << strArray[i] << std::endl;
    std::cout << "-------------------Testing with out of range 15-------------------" << std::endl;
    try
    {
        std::cout << intArray[15] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------Testing with out of range -1-------------------" << std::endl;
    try
    {
        std::cout << intArray[-1] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------Testing copy-------------------" << std::endl;
    Array<int> intArrayCopy(intArray);
    for (unsigned int i = 0; i < intArrayCopy.size(); ++i)
        std::cout << intArrayCopy[i] << std::endl;
    std::cout << "-------------------Testing assignment-------------------" << std::endl;
    Array<int> intArrayAssign = intArray;
    for (unsigned int i = 0; i < intArrayAssign.size(); ++i)
        std::cout << intArrayAssign[i] << std::endl;
    return 0;
}
