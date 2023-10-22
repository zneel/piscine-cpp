#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

Span::Span(unsigned int n) : n_(n), sorted_(true)
{
}

Span::~Span()
{
}

Span::Span(Span const &other) : n_(other.n_), v_(other.v_), sorted_(true)
{
}

Span &Span::operator=(Span const &rhs)
{
    if (this != &rhs)
    {
        n_ = rhs.n_;
        v_ = rhs.v_;
        sorted_ = rhs.sorted_;
    }

    return *this;
}

void Span::addNumber(int n)
{
    if (v_.size() >= n_)
        throw OutOfRangeException();
    v_.push_back(n);
    sorted_ = false;
}

int Span::shortestSpan()
{
    if (v_.size() < 2)
        throw NotEnoughElements();

    if (!sorted_)
    {
        std::sort(v_.begin(), v_.end());
        sorted_ = true;
    }

    std::vector<int> diff(v_.size());
    std::adjacent_difference(v_.begin(), v_.end(), diff.begin());

    return *std::min_element(diff.begin() + 1, diff.end());
}

int Span::longestSpan()
{
    if (v_.size() < 2)
        throw NotEnoughElements();

    if (!sorted_)
    {
        std::sort(v_.begin(), v_.end());
        sorted_ = true;
    }

    return v_.back() - v_.front();
}

void Span::fill(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (std::distance(begin, end) > n_)
        throw OutOfRangeException();
    v_.insert(v_.end(), begin, end);
    sorted_ = false;
}

const char *Span::OutOfRangeException::what() const throw()
{
    return "Out of range";
}

const char *Span::NotEnoughElements::what() const throw()
{
    return "Not enough elements";
}
