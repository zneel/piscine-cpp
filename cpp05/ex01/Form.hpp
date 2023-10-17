#pragma once

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 public:
  Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExec);
  Form(Form const&);
  ~Form();
  Form& operator=(Form const&);

  static const int high = 1;
  static const int low = 150;

  std::string getName() const;
  bool getSigned() const;
  int getGradeRequiredToSign() const;
  int getGradeRequiredToExec() const;
  void beSigned(Bureaucrat const&);

 private:
  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };

  std::string const name_;
  bool signed_;
  int const gradeRequiredToSign_;
  int const gradeRequiredToExec_;
};

std::ostream& operator<<(std::ostream& o, Form const& i);
