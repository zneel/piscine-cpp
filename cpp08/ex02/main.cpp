#include "MutantStack.hpp"
#include <exception>
#include <iostream>
#include <list>
#include <stack>

int main()
{
    {
        std::cout << "Subject tests:" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator start = mstack.begin();
        MutantStack<int>::iterator end = mstack.end();
        ++start;
        --start;
        while (start != end)
        {
            std::cout << *start << std::endl;
            ++start;
        }
        std::stack<int> s(mstack);
    }
    {
        std::cout << "List tests:" << std::endl;
        std::list<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);
        std::list<int>::iterator start = mstack.begin();
        std::list<int>::iterator end = mstack.end();
        ++start;
        --start;
        while (start != end)
        {
            std::cout << *start << std::endl;
            ++start;
        }
        std::list<int> s(mstack);
    }
    return 0;
}
