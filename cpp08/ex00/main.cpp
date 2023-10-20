#include "easyfind.hpp"
#include <deque>
#include <exception>
#include <list>
#include <stack>
#include <vector>

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    easyfind(v, 2);
    easyfind(v, 10);

    std::deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    easyfind(d, 2);
    easyfind(d, 10);

    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    easyfind(l, 2);
    easyfind(l, 10);

    return 0;
}
