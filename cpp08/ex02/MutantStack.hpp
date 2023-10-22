#pragma once

#include <deque>
#include <stack>

template <class T> class MutantStack : public std::stack<T>
{
  public:
    MutantStack()
    {
    }

    MutantStack(MutantStack const &other) : std::stack<T>(other)
    {
    }

    MutantStack &operator=(MutantStack const &rhs)
    {
        if (this != &rhs)
            this->c = rhs.c;

        return *this;
    }

    ~MutantStack()
    {
    }

    typedef typename std::stack<int>::container_type::iterator iterator;
    typedef typename std::stack<int>::container_type::const_iterator const_iterator;

    iterator begin()
    {
        return this->c.begin();
    }

    iterator end()
    {
        return this->c.end();
    }

    const_iterator begin() const
    {
        return this->c.begin();
    }

    const_iterator end() const
    {
        return this->c.end();
    }
};
