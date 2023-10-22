#pragma once

#include <ostream>
#include <stdexcept>

template <typename T> class Array
{
  public:
    Array<T>() : array_(NULL), size_(0)
    {
    }

    // () after T[n] calls the default T constructor
    Array<T>(unsigned int n) : array_(new T[n]()), size_(n)
    {
    }

    ~Array<T>()
    {
        delete[] array_;
    }

    Array<T>(Array<T> const &other)
    {
        size_ = other.size();
        array_ = new T[other.size()];
        for (unsigned int i = 0; i < size(); ++i)
            array_[i] = other.array_[i];
    }

    Array<T> &operator=(Array<T> const &rhs)
    {
        if (this != &rhs)
        {
            delete[] array_;
            array_ = new T[rhs.size()];
            size_ = rhs.size();
            for (unsigned int i = 0; i < rhs.size(); ++i)
                array_[i] = rhs.array_[i];
        }
        return *this;
    }

    T &operator[](unsigned int i)
    {
        if (i >= size_)
            throw std::out_of_range("Index out of range");
        return array_[i];
    }

    unsigned int size() const
    {
        return size_;
    }

  private:
    T *array_;
    unsigned int size_;
};
