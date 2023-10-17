#pragma once

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
 public:
  AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExec);
  AForm(AForm const&);
  virtual ~AForm();
  AForm& operator=(AForm const&);

  static const int high = 1;
  static const int low = 150;

  std::string getName() const;
  bool getSigned() const;
  int getGradeRequiredToSign() const;
  int getGradeRequiredToExec() const;
  void beSigned(Bureaucrat const&);
  virtual void execute(Bureaucrat const& executor) const = 0;

 protected:
  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };

 private:
  std::string const name_;
  bool signed_;
  int const gradeRequiredToSign_;
  int const gradeRequiredToExec_;
};

std::ostream& operator<<(std::ostream& o, AForm const& i);
