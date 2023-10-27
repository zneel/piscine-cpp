#include "PmergeMe.hpp"
#include <deque>

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const &other)
{
    (void)other;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
    if (this != &rhs)
    {
    }
    return *this;
}

int PmergeMe::jacobsthalNumber_(int n)
{
    if (n == 0)
        return 2;
    if (n == 1)
        return 2;
    return jacobsthalNumber_(n - 1) + 2 * jacobsthalNumber_(n - 2);
}

void PmergeMe::merge_(VectorPair &pairs, int n, std::less<int> comp)
{
    if (n <= 0 || !comp(pairs[n].second, pairs[n - 1].second))
        return;
    std::swap(pairs[n], pairs[n - 1]);
    merge_(pairs, n - 1, comp);
}

void PmergeMe::pairsOfPairs_(VectorPair &pairs, int n, std::less<int> comp)
{
    if (n <= 1)
        return;
    pairsOfPairs_(pairs, n - 1, comp);
    merge_(pairs, n - 1, comp);
}

void PmergeMe::makePairsFromInput_(std::vector<int> &input, std::less<int> comp)
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

void PmergeMe::insertSort_(std::vector<int> &input, std::less<int> comp)
{
    input.insert(input.begin(), vecPairs_.begin()->first);
    for (int k = 1;; ++k)
    {
        int dist = jacobsthalNumber_(k);
        if (dist > static_cast<int>(input.size() - 1))
            break;
        VectorIntIterator insertionPoint =
            std::upper_bound(input.begin(), input.begin() + dist, vecPairs_[k].first, comp);
        input.insert(insertionPoint, vecPairs_[k].first);
    }
}

void PmergeMe::mergeInsertSort(std::vector<int> &input, std::less<int> comp)
{
    if (input.size() <= 1)
        return;
    makePairsFromInput_(input, comp);
    pairsOfPairs_(vecPairs_, vecPairs_.size(), comp);
    std::vector<int> mainChain;
    for (VectorPair::iterator it = vecPairs_.begin(); it != vecPairs_.end(); ++it)
        mainChain.push_back(it->second);
    insertSort_(mainChain, comp);
    if (!isEven_)
    {
        VectorIntIterator pos = std::upper_bound(mainChain.begin(), mainChain.end(), spare_, comp);
        mainChain.insert(pos, spare_);
    }
    input = mainChain;
}

//////// DEQUE VERSION ////////

void PmergeMe::merge_(DequePair &pairs, int n, std::less<int> comp)
{
    if (n <= 0 || !comp(pairs[n].second, pairs[n - 1].second))
        return;
    std::swap(pairs[n], pairs[n - 1]);
    merge_(pairs, n - 1, comp);
}

void PmergeMe::pairsOfPairs_(DequePair &pairs, int n, std::less<int> comp)
{
    if (n <= 1)
        return;
    pairsOfPairs_(pairs, n - 1, comp);
    merge_(pairs, n - 1, comp);
}

void PmergeMe::makePairsFromInput_(std::deque<int> &input, std::less<int> comp)
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

void PmergeMe::insertSort_(std::deque<int> &input, std::less<int> comp)
{
    input.insert(input.begin(), vecPairs_.begin()->first);
    for (int k = 1;; ++k)
    {
        int dist = jacobsthalNumber_(k);
        if (dist > static_cast<int>(input.size() - 1))
            break;
        DequeIntIterator insertionPoint =
            std::upper_bound(input.begin(), input.begin() + dist, dequePairs_[k].first, comp);
        input.insert(insertionPoint, dequePairs_[k].first);
    }
}

void PmergeMe::mergeInsertSort(std::deque<int> &input, std::less<int> comp)
{
    if (input.size() <= 1)
        return;
    makePairsFromInput_(input, comp);
    pairsOfPairs_(dequePairs_, dequePairs_.size(), comp);
    std::deque<int> mainChain;
    for (DequePair::iterator it = dequePairs_.begin(); it != dequePairs_.end(); ++it)
        mainChain.push_back(it->second);
    insertSort_(mainChain, comp);
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

bool PmergeMe::isSorted(std::vector<int> &v)
{
    for (VectorIntIterator it = v.begin(); it != v.end() - 1; ++it)
    {
        if (std::less<int>()(*(it + 1), *it))
            return false;
    }
    return true;
}

bool PmergeMe::isSorted(std::deque<int> &v)
{
    for (DequeIntIterator it = v.begin(); it != v.end() - 1; ++it)
    {
        if (std::less<int>()(*(it + 1), *it))
            return false;
    }
    return true;
}
