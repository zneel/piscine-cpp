#pragma once

#include <vector>
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
    void fill(std::vector<int>::iterator begin, std::vector<int>::iterator end);

  private:
    void mergeUnsorted();
    unsigned int n_;
    std::vector<int> v_;
    bool sorted_;

    class OutOfRangeException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class NotEnoughElements : public std::exception
    {
        virtual const char *what() const throw();
    };
};
