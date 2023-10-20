#pragma once

#include <algorithm>
#include <iostream>

template <typename T> void easyfind(T const &container, int const i)
{
    typedef typename T::const_iterator iterator_type;
    iterator_type it = std::find(container.begin(), container.end(), i);
    if (it != container.end())
        std::cout << "Found " << i << std::endl;
    else
        std::cout << "Not found " << i << std::endl;
}
