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

    void merge_insert_sort_vector(std::vector<int> &d, int (*comp)(int a, int b))
    {
        if (d.size() < 2)
            return;
        bool isOdd = d.size() % 2 == 0;
        std::vector<int>::iterator endOdd = isOdd ? d.end() : d.end() - 1;
        std::vector<int> mainChain;
        for (std::vector<int>::iterator it = d.begin(); it != endOdd; it += 2)
        {
            if (comp(it[0], it[1]))
                mainChain.push_back(it[1]);
            else
                mainChain.push_back(it[0]);
        }
        for (std::vector<int>::iterator it = d.begin(); it != d.end(); ++it)
        {
            std::cout << "d: " << *it << " " << std::endl;
        }

        for (std::vector<int>::iterator it = mainChain.begin(); it != mainChain.end(); ++it)
        {
            std::cout << "mainchain: " << *it << " " << std::endl;
        }
        merge_insert_sort_vector(mainChain, comp);
        if (!isOdd)
            mainChain.push_back(*d.end());
        // std::vector<int>::iterator deqStart = d.begin();
        // std::vector<int>::iterator mainChainStart = mainChain.begin();
        // while (deqStart != d.end() && mainChainStart != mainChain.end())
        // {
        //     if (!comp(*deqStart, *mainChainStart))
        //     {
        //         d.insert(deqStart, *mainChainStart);
        //         ++mainChainStart;
        //     }
        //     ++deqStart;
        // }
    }
};
