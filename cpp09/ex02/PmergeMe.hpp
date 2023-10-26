#pragma once

#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

// clang-format off
typedef std::vector<std::pair<int, int> > VectorPair;
// clang-format on

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

    void insert(VectorPair &pairs, int n, bool (*comp)(int, int))
    {
        if (n <= 0 || !comp(pairs[n].second, pairs[n - 1].second))
            return;
        std::swap(pairs[n], pairs[n - 1]);
        insert(pairs, n - 1, comp);
    }

    void vectorPairs(VectorPair &pairs, int n, bool (*comp)(int, int))
    {
        if (n <= 1)
            return;
        vectorPairs(pairs, n - 1, comp);
        insert(pairs, n - 1, comp);
    }

    void makePairsFromInput(std::vector<int> &input, bool (*comp)(int a, int b))
    {
        isEven_ = input.size() % 2 == 0;
        std::vector<int>::iterator newEnd = isEven_ ? input.end() : input.end() - 1;
        if (!isEven_)
            spare_ = input.back();
        for (std::vector<int>::iterator it = input.begin(); it != newEnd; it += 2)
        {
            if (comp(it[1], it[0]))
                vecPairs_.push_back(std::make_pair(it[1], it[0]));
            else
                vecPairs_.push_back(std::make_pair(it[0], it[1]));
        }
    }

    void insertSortVector(std::vector<int> &input, bool (*comp)(int a, int b))
    {
        (void)comp;
        // insert vecPairs_ in correct position following the jacobshtal sequence
        std::vector<int>::iterator it = input.begin();
        for (VectorPair::iterator itPair = vecPairs_.begin(); itPair != vecPairs_.end(); ++itPair)
        {
            int jacobsthal = jacobsthalNumber(itPair - vecPairs_.begin());
            std::advance(it, jacobsthal);
            input.insert(it, itPair->first);
            ++it;
        }
    }

    void mergeInsertSortVector(std::vector<int> &input, bool (*comp)(int a, int b))
    {
        makePairsFromInput(input, comp);
        std::cout << "pairs: ";
        for (VectorPair::iterator it = vecPairs_.begin(); it != vecPairs_.end(); ++it)
            std::cout << "(" << it->first << ", " << it->second << ") ";
        std::cout << std::endl;
        vectorPairs(vecPairs_, vecPairs_.size(), comp);
        std::vector<int> result;
        for (VectorPair::iterator it = vecPairs_.begin(); it != vecPairs_.end(); ++it)
            result.push_back(it->second);
        input = result;
        std::cout << "input: ";
        for (std::vector<int>::iterator it = input.begin(); it != input.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        insertSortVector(input, comp);
        if (!isEven_)
        {
            int pos = std::upper_bound(input.begin(), input.end(), spare_, comp) - input.begin();
            input.insert(input.begin() + pos, spare_);
        }
    }

  private:
    VectorPair vecPairs_;
    int spare_;
    bool isEven_;
};
