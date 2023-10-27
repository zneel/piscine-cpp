#pragma once

#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <stdint.h>
#include <utility>
#include <vector>

// clang-format off
typedef std::vector<std::pair<int, int> > VectorPair;
typedef std::deque<std::pair<int, int> > DequePair;
// clang-format on

typedef std::vector<int>::iterator VectorIntIterator;
typedef std::deque<int>::iterator DequeIntIterator;

class PmergeMe
{
  public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(PmergeMe const &);
    PmergeMe &operator=(PmergeMe const &);
    void mergeInsertSort(std::vector<int> &input, std::less<int> comp);
    void mergeInsertSort(std::deque<int> &input, std::less<int> comp);
    bool hasDuplicates(std::vector<int> &input);
    bool hasDuplicates(std::deque<int> &input);
    bool isSorted(std::vector<int> &input);
    bool isSorted(std::deque<int> &input);

  private:
    int jacobsthalNumber_(int n);
    void merge_(VectorPair &pairs, int n, std::less<int> comp);
    void merge_(DequePair &pairs, int n, std::less<int> comp);
    void pairsOfPairs_(VectorPair &pairs, int n, std::less<int> comp);
    void pairsOfPairs_(DequePair &pairs, int n, std::less<int> comp);
    void makePairsFromInput_(std::vector<int> &input, std::less<int> comp);
    void makePairsFromInput_(std::deque<int> &input, std::less<int> comp);
    void insertSort_(std::vector<int> &input, std::less<int> comp);
    void insertSort_(std::deque<int> &input, std::less<int> comp);

    VectorPair vecPairs_;
    DequePair dequePairs_;
    int spare_;
    bool isEven_;
};
