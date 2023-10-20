#include "Span.hpp"
#include <deque>
#include <exception>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

int main()
{
    Span sp = Span(6);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.addNumber(1);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}
