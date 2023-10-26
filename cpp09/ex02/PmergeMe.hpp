#pragma once

#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

class PmergeMe
{
  public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(PmergeMe const &);
    PmergeMe &operator=(PmergeMe const &);

    int jacobsthalNumber(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        return jacobsthalNumber(n - 1) + 2 * jacobsthalNumber(n - 2);
    }

    void grouped_iter_swap(std::vector<int>::iterator a, std::vector<int>::iterator b, int n)
    {
        std::swap_ranges(a, b + n, b);
    }

    void mergeInsertSortVector(std::vector<int>::iterator start, std::vector<int>::iterator end,
                               bool (*comp)(int a, int b), int itSize)
    {
        (void)itSize;
        std::cout << std::endl;
        long size = std::distance(start, end);
        if (size <= 1)
            return;
        bool isEven = size % 2 == 0;
        std::vector<int>::iterator newEnd = isEven ? end : end - 1;
        // make pairs and sort bigger numbers to the right
        for (std::vector<int>::iterator it = start; start != newEnd; start += 2)
        {
            if (comp(it[1], it[0]))
                grouped_iter_swap(it, it + 1, 2);
        }
        std::cout << "start: ";
        for (std::vector<int>::iterator it = start; it != end; ++it)
            std::cout << *it << " ";
        mergeInsertSortVector(start, newEnd, comp, 2);
    }
};
