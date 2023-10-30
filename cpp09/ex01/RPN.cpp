#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(RPN const &other) : stack_(other.stack_)
{
}

RPN &RPN::operator=(RPN const &rhs)
{
    if (this != &rhs)
        stack_ = rhs.stack_;
    return *this;
}

int64_t RPN::evaluate(std::string const &expr)
{
    std::string line;
    std::istringstream iss(expr);
    if (expr.find_first_of("0123456789+-/ *") == std::string::npos)
        throw ErrorException();
    while (std::getline(iss, line, ' '))
    {
        if (line.empty())
            continue;
        if (line.size() == 1 && line.find_first_of("0123456789") != std::string::npos)
        {
            if (std::atoi(line.c_str()) > 9 || std::atoi(line.c_str()) < 0)
                throw ErrorException();
            stack_.push(std::atoi(line.c_str()));
        }
        else if (line.find_first_of("+/-*") != std::string::npos)
        {
            if (stack_.size() < 2)
                throw ErrorException();
            int64_t b = stack_.top();
            stack_.pop();
            int64_t a = stack_.top();
            stack_.pop();
            int64_t result = do_operation(a, b, line);
            stack_.push(result);
        }
        else
            throw ErrorException();
    }
    if (stack_.size() > 1 || stack_.size() == 0)
        throw ErrorException();
    return stack_.top();
}

int64_t RPN::do_operation(int64_t a, int64_t b, std::string const &op) const
{
    switch (op.at(0))
    {
    case '*':
        return a * b;
    case '/':
        if (b == 0)
            throw ErrorException();
        return a / b;
    case '+':
        return a + b;
    case '-':
        return a - b;
    default:
        throw ErrorException();
    }
}

const char *RPN::ErrorException::what() const throw()
{
    return "Error";
}
