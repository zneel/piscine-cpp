#pragma once

#include <cstdlib>
#include <iostream>
#include <list>
#include <sstream>
#include <stack>
#include <stdint.h>
#include <string>

class RPN
{
  public:
    RPN();
    ~RPN();
    RPN(RPN const &other);
    RPN &operator=(RPN const &rhs);

    int64_t evaluate(std::string const &expr);

  private:
    int64_t do_operation(int64_t a, int64_t b, std::string const &op) const;
    // clang-format off
    std::stack<int64_t,std::list<int64_t> > stack_;
    // clang-format on
    class ErrorException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};
