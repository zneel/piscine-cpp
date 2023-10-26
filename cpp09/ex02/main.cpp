#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <vector>

bool compare_int(int a, int b)
{
    return a < b;
}

template <typename T> void print_container(T container)
{
    int i = 0;
    int size = container.size();
    bool flag = true;
    for (typename T::iterator iter = container.begin(); iter != container.end(); ++iter)
    {
        if (size <= 15)
            std::cout << *iter << " ";
        else
        {
            if (i < 8 || i + 8 >= size)
                std::cout << *iter << " ";
            else if (flag)
            {
                std::cout << "... ";
                flag = false;
            }
        }
        i++;
    }
    std::cout << std::endl;
}

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "Usage: ./PMerge [sequence]" << std::endl;
        return 1;
    }
    PmergeMe pmergevector;
    std::vector<int> input;
    for (int i = 1; i < ac; ++i)
    {
        int v = std::atoi(av[i]);
        if (v < 0)
        {
            std::cout << "Error" << std::endl;
            return (1);
        }
        input.insert(input.begin() + i - 1, v);
    }
    std::cout << "Vector before: ";
    print_container(input);
    const std::clock_t c_start = std::clock();
    // clang-format off
    pmergevector.mergeInsertSortVector(input.begin(),input.end(), compare_int,1);
    // clang-format on
    const std::clock_t c_end = std::clock();
    std::cout << "Vector after: ";
    print_container(input);
    std::cout << std::fixed << std::setprecision(4) << "CPU time used: " << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC
              << " ms" << std::endl;
}
