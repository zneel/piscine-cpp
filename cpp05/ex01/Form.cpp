#include "Form.hpp"

Form::Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExec)
    : name_(name),
      signed_(false),
      gradeRequiredToSign_(gradeRequiredToSign),
      gradeRequiredToExec_(gradeRequiredToExec) {
  if (gradeRequiredToSign_ < high || gradeRequiredToExec_ < high)
    throw Form::GradeTooHighException();
  else if (gradeRequiredToSign_ > low || gradeRequiredToExec_ > low)
    throw Form::GradeTooLowException();
}

std::string Form::getName() const { return name_; }

bool Form::getSigned() const { return signed_; }

int Form::getGradeRequiredToSign() const { return gradeRequiredToSign_; }

int Form::getGradeRequiredToExec() const { return gradeRequiredToExec_; }

Form::Form(const Form& other)
    : name_(other.name_),
      signed_(false),
      gradeRequiredToSign_(other.gradeRequiredToSign_),
      gradeRequiredToExec_(other.gradeRequiredToExec_) {}

Form::~Form() {}

Form& Form::operator=(Form const& rhs) {
  if (this != &rhs) {
    signed_ = rhs.signed_;
  }
  return *this;
}

std::ostream& operator<<(std::ostream& o, Form const& f) {
  o << "Form informations:"
    << "name: " << f.getName() << " signed: " << f.getSigned()
    << " grade required to sign: " << f.getGradeRequiredToSign()
    << " grade required to exec:" << f.getGradeRequiredToExec();
  return o;
}

const char* Form::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

void Form::beSigned(Bureaucrat const& b) {
  if (b.getGrade() > gradeRequiredToSign_) {
    throw Form::GradeTooLowException();
  }

  signed_ = true;
}
