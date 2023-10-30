#include "PmergeMe.hpp"
#include <deque>

PmergeMe::PmergeMe() : vecPairs_(0), dequePairs_(0), spare_(0), isEven_(false)
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const &other)
    : vecPairs_(other.vecPairs_), dequePairs_(other.dequePairs_), spare_(other.spare_), isEven_(other.isEven_)
{
    (void)other;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
    if (this != &rhs)
    {
        vecPairs_ = rhs.vecPairs_;
        dequePairs_ = rhs.dequePairs_;
        spare_ = rhs.spare_;
        isEven_ = rhs.isEven_;
    }
    return *this;
}

int PmergeMe::jacobsthalNumber_(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobsthalNumber_(n - 1) + 2 * jacobsthalNumber_(n - 2);
}

void PmergeMe::merge_(VectorPair &pairs, int n, bool (*comp)(int a, int b))
{
    if (n <= 0 || !comp(pairs[n].second, pairs[n - 1].second))
        return;
    std::swap(pairs[n], pairs[n - 1]);
    merge_(pairs, n - 1, comp);
}

void PmergeMe::pairsOfPairs_(VectorPair &pairs, int n, bool (*comp)(int a, int b))
{
    if (n <= 1)
        return;
    pairsOfPairs_(pairs, n - 1, comp);
    merge_(pairs, n - 1, comp);
}

void PmergeMe::makePairsFromInput_(std::vector<int> &input, bool (*comp)(int a, int b))
{
    isEven_ = input.size() % 2 == 0;
    VectorIntIterator newEnd = isEven_ ? input.end() : input.end() - 1;
    if (!isEven_)
        spare_ = input.back();
    for (VectorIntIterator it = input.begin(); it != newEnd; it += 2)
    {
        if (comp(it[1], it[0]))
            vecPairs_.push_back(std::make_pair(it[1], it[0]));
        else
            vecPairs_.push_back(std::make_pair(it[0], it[1]));
    }
}

void PmergeMe::insertSort_(std::vector<int> &input, bool (*comp)(int a, int b))
{
    for (int k = 0;; ++k)
    {
        int dist = jacobsthalNumber_(k);
        if (dist >= static_cast<int>(vecPairs_.size()))
            break;
        VectorPair::iterator it = vecPairs_.begin();
        std::advance(it, dist);
        while (true)
        {
            VectorIntIterator insertionPoint = std::upper_bound(input.begin(), input.end(), it->first, comp);
            input.insert(insertionPoint, it->first);
            it = vecPairs_.erase(it);
            if (it == vecPairs_.begin())
                break;
            --it;
        }
    }
}

void PmergeMe::mergeInsertSort(std::vector<int> &input, bool (*comp)(int a, int b))
{
    if (input.size() <= 1)
        return;
    makePairsFromInput_(input, comp);
    pairsOfPairs_(vecPairs_, vecPairs_.size(), comp);
    std::vector<int> mainChain;
    for (VectorPair::iterator it = vecPairs_.begin(); it != vecPairs_.end(); ++it)
        mainChain.push_back(it->second);
    mainChain.insert(mainChain.begin(), vecPairs_.begin()->first);
    vecPairs_.erase(vecPairs_.begin());
    insertSort_(mainChain, comp);
    while (!vecPairs_.empty())
    {
        VectorPair::iterator last = vecPairs_.end();
        VectorIntIterator insertionPoint = std::upper_bound(mainChain.begin(), mainChain.end(), last->first, comp);
        mainChain.insert(insertionPoint, last->first);
        vecPairs_.pop_back();
    }
    if (!isEven_)
    {
        VectorIntIterator pos = std::upper_bound(mainChain.begin(), mainChain.end(), spare_, comp);
        mainChain.insert(pos, spare_);
    }
    input = mainChain;
}

//////// DEQUE VERSION ////////

void PmergeMe::merge_(DequePair &pairs, int n, bool (*comp)(int a, int b))
{
    if (n <= 0 || !comp(pairs[n].second, pairs[n - 1].second))
        return;
    std::swap(pairs[n], pairs[n - 1]);
    merge_(pairs, n - 1, comp);
}

void PmergeMe::pairsOfPairs_(DequePair &pairs, int n, bool (*comp)(int a, int b))
{
    if (n <= 1)
        return;
    pairsOfPairs_(pairs, n - 1, comp);
    merge_(pairs, n - 1, comp);
}

void PmergeMe::makePairsFromInput_(std::deque<int> &input, bool (*comp)(int a, int b))
{
    isEven_ = input.size() % 2 == 0;
    DequeIntIterator newEnd = isEven_ ? input.end() : input.end() - 1;
    if (!isEven_)
        spare_ = input.back();
    for (DequeIntIterator it = input.begin(); it != newEnd; it += 2)
    {
        if (comp(it[1], it[0]))
            dequePairs_.push_back(std::make_pair(it[1], it[0]));
        else
            dequePairs_.push_back(std::make_pair(it[0], it[1]));
    }
}

void PmergeMe::insertSort_(std::deque<int> &input, bool (*comp)(int a, int b))
{
    for (int k = 0;; ++k)
    {
        int dist = jacobsthalNumber_(k);
        if (dist >= static_cast<int>(dequePairs_.size()))
            break;
        DequePair::iterator it = dequePairs_.begin();
        std::advance(it, dist);
        while (true)
        {
            DequeIntIterator insertionPoint = std::upper_bound(input.begin(), input.end(), it->first, comp);
            input.insert(insertionPoint, it->first);
            it = dequePairs_.erase(it);
            if (it == dequePairs_.begin())
                break;
            --it;
        }
    }
}

void PmergeMe::mergeInsertSort(std::deque<int> &input, bool (*comp)(int a, int b))
{
    if (input.size() <= 1)
        return;
    makePairsFromInput_(input, comp);
    pairsOfPairs_(dequePairs_, dequePairs_.size(), comp);
    std::deque<int> mainChain(0);
    for (DequePair::iterator it = dequePairs_.begin(); it != dequePairs_.end(); ++it)
        mainChain.push_back(it->second);
    mainChain.insert(mainChain.begin(), dequePairs_.begin()->first);
    dequePairs_.erase(dequePairs_.begin());
    insertSort_(mainChain, comp);
    while (!dequePairs_.empty())
    {
        DequePair::iterator last = dequePairs_.end();
        DequeIntIterator insertionPoint = std::upper_bound(mainChain.begin(), mainChain.end(), last->first, comp);
        mainChain.insert(insertionPoint, last->first);
        dequePairs_.pop_back();
    }
    if (!isEven_)
    {
        DequeIntIterator pos = std::upper_bound(mainChain.begin(), mainChain.end(), spare_, comp);
        mainChain.insert(pos, spare_);
    }
    input = mainChain;
}

///////// HELPERS /////////
bool PmergeMe::hasDuplicates(std::vector<int> &v)
{
    for (VectorIntIterator it = v.begin(); it != v.end(); ++it)
    {
        for (VectorIntIterator it2 = it + 1; it2 != v.end(); ++it2)
        {
            if (*it == *it2)
                return true;
        }
    }
    return false;
}

bool PmergeMe::hasDuplicates(std::deque<int> &v)
{
    for (DequeIntIterator it = v.begin(); it != v.end(); ++it)
    {
        for (DequeIntIterator it2 = it; it2 != v.end(); ++it2)
        {
            if (*it == *it2)
                return true;
        }
    }
    return false;
}

bool PmergeMe::isSorted(std::vector<int> &v, bool (*comp)(int a, int b))
{
    for (VectorIntIterator it = v.begin(); it != v.end() - 1; ++it)
    {
        if (comp(*(it + 1), *it))
            return false;
    }
    return true;
}

bool PmergeMe::isSorted(std::deque<int> &v, bool (*comp)(int a, int b))
{
    for (DequeIntIterator it = v.begin(); it != v.end() - 1; ++it)
    {
        if (comp(*(it + 1), *it))
            return false;
    }
    return true;
}
