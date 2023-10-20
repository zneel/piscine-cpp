#include "Span.hpp"
#include <algorithm>
#include <deque>
#include <limits>
#include <numeric>

Span::Span(unsigned int n) : n_(n)
{
}

Span::~Span()
{
}

Span::Span(Span const &other) : n_(other.n_)
{
    d_ = other.d_;
}

Span &Span::operator=(Span const &rhs)
{
    if (this != &rhs)
    {
        n_ = rhs.n_;
        d_ = rhs.d_;
    }

    return *this;
}

void Span::addNumber(int n)
{
    if (d_.size() == n_)
        throw std::exception();
    std::deque<int>::iterator it = std::lower_bound(d_.begin(), d_.end(), n);
    d_.insert(it, n);
}

int Span::shortestSpan()
{
    if (d_.size() < 2)
        throw std::exception();
    std::deque<int> diff(d_.size());
    std::adjacent_difference(d_.begin(), d_.end(), diff.begin());

    return *std::min_element(diff.begin() + 1, diff.end());
}

int Span::longestSpan()
{
    if (d_.size() < 2)
        throw std::exception();

    return d_.back() - d_.front();
}
