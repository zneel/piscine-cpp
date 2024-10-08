#pragma once

#include <exception>
#include <ostream>
#include <string>

#include "Form.hpp"

class Form;

class Bureaucrat
{
  public:
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();
    Bureaucrat &operator=(Bureaucrat const &);
    Bureaucrat(Bureaucrat const &);

    static const int high = 1;
    static const int low = 150;

    std::string getName() const;
    int getGrade() const;
    void signForm(Form &f) const;

    Bureaucrat &operator--();
    Bureaucrat &operator++();

  private:
    class GradeTooHighException : public std::exception
    {
      public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
      public:
        const char *what() const throw();
    };

    std::string const name_;
    int grade_;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);
