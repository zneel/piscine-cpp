#pragma once

#include <cstddef>
#include <stdint.h>

template <typename T> void iter(T *array, std::size_t len, void (*f)(T const &))
{
    for (std::size_t i = 0; i < len; ++i)
        f(array[i]);
}
