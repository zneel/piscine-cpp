#pragma once

#include <ostream>
#include <stdexcept>

template <typename T> class Array
{
  public:
    Array<T>() : array(NULL), size_(0)
    {
    }

    // () after T[n] calls the default T constructor
    Array<T>(unsigned int n) : array(new T[n]()), size_(n)
    {
    }

    ~Array<T>()
    {
        delete[] array;
    }

    Array<T>(Array<T> const &other)
    {
        size_ = other.size();
        array = new T[other.size()];
        for (unsigned int i = 0; i < other.size(); ++i)
            array[i] = other.array[i];
    }

    Array<T> &operator=(Array<T> const &rhs)
    {
        if (this != &rhs)
        {
            delete[] array;
            array = new T[rhs.size()];
            size_ = rhs.size();
            for (unsigned int i = 0; i < rhs.size(); ++i)
                array[i] = rhs.array[i];
        }
        return *this;
    }

    T &operator[](unsigned int i)
    {
        if (i >= size_)
            throw std::out_of_range("Index out of range");
        return array[i];
    }

    unsigned int size() const
    {
        return size_;
    }

  private:
    T *array;
    unsigned int size_;
};
