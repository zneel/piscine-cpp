#include "Bureaucrat.hpp"

#include <exception>
#include <iostream>

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade)
{
    if (grade_ < high)
        throw Bureaucrat::GradeTooHighException();
    if (grade_ > low)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : name_(other.name_), grade_(other.grade_)
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

void Bureaucrat::signForm(AForm &f) const
{
    try
    {
        if (f.getSigned())
            return;
        f.beSigned(*this);
        std::cout << name_ << " signed " << f.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << name_ << " couldn't sign " << f.getName() << " because " << e.what() << "." << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
        std::cout << name_ << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

Bureaucrat &Bureaucrat::operator--()
{
    if (grade_ + 1 > low)
        throw Bureaucrat::GradeTooLowException();
    ++grade_;
    return *this;
}

Bureaucrat &Bureaucrat::operator++()
{
    if (grade_ - 1 < high)
        throw Bureaucrat::GradeTooHighException();
    --grade_;
    return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
