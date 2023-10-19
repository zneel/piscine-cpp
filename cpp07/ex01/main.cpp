#include "iter.hpp"
#include <iostream>

void print(int const &x)
{
    std::cout << x << std::endl;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    iter(array, 5, print);
    return 0;
}
