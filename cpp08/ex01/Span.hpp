#pragma once

#include <deque>
class Span
{
  public:
    Span(unsigned int n);
    ~Span();
    Span(Span const &other);
    Span &operator=(Span const &rhs);

    void addNumber(int n);
    int shortestSpan();
    int longestSpan();

  private:
    unsigned int n_;
    std::deque<int> d_;
};
