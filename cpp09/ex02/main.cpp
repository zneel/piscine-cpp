#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <vector>

template <typename T> void print(T &cont)
{
    size_t size = cont.size();
    if (size <= 10)
    {
        for (size_t i = 0; i < size; ++i)
            std::cout << cont[i] << " ";
    }
    else
    {
        for (size_t i = 0; i < 5; ++i)
            std::cout << cont[i] << " ";
        std::cout << "[...] ";
        for (size_t i = size - 5; i < size; ++i)
            std::cout << cont[i] << " ";
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
    PmergeMe pmerge;
    std::vector<int> vect;
    std::deque<int> deq;
    for (int i = 1; i < ac; ++i)
    {
        int v = std::atoi(av[i]);
        if (v < 0)
        {
            std::cout << "Error" << std::endl;
            return (1);
        }
        vect.push_back(v);
    }
    if (pmerge.hasDuplicates(vect))
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
        deq.push_back(*it);
    size_t originalVectSize = vect.size();
    size_t originalDeqSize = deq.size();
    std::cout << "Before: ";
    print(vect);
    const std::clock_t v_start = std::clock();
    pmerge.mergeInsertSort(vect, std::less<int>());
    const std::clock_t v_end = std::clock();
    bool isSortedVect = pmerge.isSorted(vect);
    std::cout << "After:  ";
    print(vect);
    std::cout << "Time to process a range of 5 elements with std::vector"
              << " : " << 1000.0 * (v_end - v_start) / CLOCKS_PER_SEC << " ms" << std::endl;
    const std::clock_t d_start = std::clock();
    pmerge.mergeInsertSort(deq, std::less<int>());
    const std::clock_t d_end = std::clock();
    bool isSortedDeq = pmerge.isSorted(deq);
    std::cout << "Time to process a range of 5 elements with std::deque"
              << " : " << 1000.0 * (d_end - d_start) / CLOCKS_PER_SEC << " ms" << std::endl;

    std::cout << "Original vector size: " << originalVectSize << std::endl;
    std::cout << "Original deque size: " << originalDeqSize << std::endl;
    std::cout << "Final vector size: " << vect.size() << std::endl;
    std::cout << "Final deque size: " << deq.size() << std::endl;

    return isSortedDeq && isSortedVect;
}
