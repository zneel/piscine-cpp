#include "whatever.hpp"
#include <iostream>

int main()
{
    // Testing with integers
    int x = 5, y = 10;
    std::cout << "Integers:\n";
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    swap(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;
    std::cout << "Min of x and y: " << min(x, y) << std::endl;
    std::cout << "Max of x and y: " << max(x, y) << std::endl;

    // Testing with strings
    std::string s1 = "truc", s2 = "machin";
    std::cout << "\nStrings:\n";
    std::cout << "Before swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;
    swap(s1, s2);
    std::cout << "After swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;
    std::cout << "Min of s1 and s2: " << ::min(s1, s2) << std::endl;
    std::cout << "Max of s1 and s2: " << ::max(s1, s2) << std::endl;

    return 0;
}
