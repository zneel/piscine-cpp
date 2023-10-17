#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade), high_(1), low_(150)
{
    if (grade_ < high_)
        throw Bureaucrat::GradeTooHighException();
    if (grade_ > low_)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : name_(other.name_), grade_(other.grade_), high_(1), low_(150)
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    if (this != &rhs)
    {
        grade_ = rhs.grade_;
    }
    return *this;
}

std::string Bureaucrat::getName() const
{
    return name_;
}

int Bureaucrat::getGrade() const
{
    return grade_;
}

Bureaucrat &Bureaucrat::operator--()
{
    if (grade_ + 1 > low_)
        throw Bureaucrat::GradeTooLowException();
    ++grade_;
    return *this;
}

Bureaucrat &Bureaucrat::operator++()
{
    if (grade_ - 1 < high_)
        throw Bureaucrat::GradeTooHighException();
    --grade_;
    return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade is too low";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
