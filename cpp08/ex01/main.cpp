#include "Span.hpp"
#include <exception>
#include <iostream>
#include <vector>

int main()
{
    {
        std::cout << "==Suject" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    {
        std::cout << "==Errors" << std::endl;
        Span sp = Span(1);
        sp.addNumber(1);
        try
        {
            sp.addNumber(99);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            std::cout << sp.shortestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        std::cout << "==Fill test" << std::endl;
        std::vector<int> vec(100);
        for (int i = 0; i < 100; i++)
            vec[i] = i;
        Span sp = Span(100);
        sp.fill(vec.begin(), vec.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    {
        std::vector<int> vec(200);
        for (int i = 0; i < 200; i++)
            vec[i] = i;
        Span sp = Span(100);
        try
        {
            sp.fill(vec.begin(), vec.end());
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        std::cout << "==Big test" << std::endl;
        Span sp = Span(500000);
        for (int i = 0; i < 500000; i++)
            sp.addNumber(i);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    return 0;
}
