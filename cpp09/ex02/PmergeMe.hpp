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

    void mergeInsertSort(std::vector<int> &input, bool (*comp)(int a, int b));
    void mergeInsertSort(std::deque<int> &input, bool (*comp)(int a, int b));
    bool hasDuplicates(std::vector<int> &input);
    bool hasDuplicates(std::deque<int> &input);
    bool isSorted(std::vector<int> &input, bool (*comp)(int a, int b));
    bool isSorted(std::deque<int> &input, bool (*comp)(int a, int b));

  private:
    PmergeMe(PmergeMe const &);
    PmergeMe &operator=(PmergeMe const &);

    int jacobsthalNumber_(int n);
    void merge_(VectorPair &pairs, int n, bool (*comp)(int a, int b));
    void merge_(DequePair &pairs, int n, bool (*comp)(int a, int b));
    void pairsOfPairs_(VectorPair &pairs, int n, bool (*comp)(int a, int b));
    void pairsOfPairs_(DequePair &pairs, int n, bool (*comp)(int a, int b));
    void makePairsFromInput_(std::vector<int> &input, bool (*comp)(int a, int b));
    void makePairsFromInput_(std::deque<int> &input, bool (*comp)(int a, int b));
    void insertSort_(std::vector<int> &input, bool (*comp)(int a, int b));
    void insertSort_(std::deque<int> &input, bool (*comp)(int a, int b));

    VectorPair vecPairs_;
    DequePair dequePairs_;
    int spare_;
    bool isEven_;
};
