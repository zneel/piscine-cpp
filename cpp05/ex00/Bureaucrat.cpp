#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
    : name_(name), grade_(grade) {
  if (grade_ < 1) throw Bureaucrat::GradeTooHighException();
  if (grade_ > 150) throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
  if (this != &rhs) {
    *this = rhs;
  }
  return *this;
}

std::string Bureaucrat::getName() const { return name_; }

int Bureaucrat::getGrade() const { return grade_; }

Bureaucrat &Bureaucrat::operator--() {
  this->grade_++;
  return *this;
}

Bureaucrat &Bureaucrat::operator++() {
  this->grade_--;
  return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Bureaucrat grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Bureaucrat grade is too low";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b) {
  os << b.getName() << ", bureaucrat grade " << b.getGrade() << "."
     << std::endl;
  return os;
}
