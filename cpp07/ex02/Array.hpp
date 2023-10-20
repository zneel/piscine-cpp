#pragma once

#include <ostream>
#include <stdexcept>

template <typename T> class Array
{
  public:
    T *array;

    Array<T>() : array(new T[0]), size_(0)
    {
    }

    Array<T>(unsigned int n) : array(new T[n]), size_(n)
    {
    }

    ~Array<T>()
    {
        delete[] array;
    }

    Array<T>(Array<T> const &other) : size_(other.size_)
    {
        array = new T[other.size_];
        for (unsigned int i = 0; i < other.size_; ++i)
            array[i] = other.array[i];
    }

    Array<T> &operator=(Array<T> const &rhs)
    {
        if (this != &rhs)
        {
            delete[] array;
            array = new T[rhs.size_];
            size_ = rhs.size_;
            for (unsigned int i = 0; i < rhs.size_; ++i)
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
    unsigned int size_;
};
