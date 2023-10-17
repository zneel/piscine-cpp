#include "AForm.hpp"

AForm::AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExec)
    : name_(name),
      signed_(false),
      gradeRequiredToSign_(gradeRequiredToSign),
      gradeRequiredToExec_(gradeRequiredToExec) {
  if (gradeRequiredToSign_ < high || gradeRequiredToExec_ < high)
    throw AForm::GradeTooHighException();
  else if (gradeRequiredToSign_ > low || gradeRequiredToExec_ > low)
    throw AForm::GradeTooLowException();
}

std::string AForm::getName() const { return name_; }

bool AForm::getSigned() const { return signed_; }

int AForm::getGradeRequiredToSign() const { return gradeRequiredToSign_; }

int AForm::getGradeRequiredToExec() const { return gradeRequiredToExec_; }

AForm::AForm(const AForm& other)
    : name_(other.name_),
      signed_(false),
      gradeRequiredToSign_(other.gradeRequiredToSign_),
      gradeRequiredToExec_(other.gradeRequiredToExec_) {}

AForm::~AForm() {}

AForm& AForm::operator=(AForm const& rhs) {
  if (this != &rhs) {
    signed_ = rhs.signed_;
  }
  return *this;
}

std::ostream& operator<<(std::ostream& o, AForm const& f) {
  o << "Form informations:"
    << "name: " << f.getName() << " signed: " << f.getSigned()
    << " grade required to sign: " << f.getGradeRequiredToSign()
    << " grade required to exec:" << f.getGradeRequiredToExec();
  return o;
}

const char* AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

void AForm::beSigned(Bureaucrat const& b) {
  if (b.getGrade() > gradeRequiredToSign_) {
    throw AForm::GradeTooLowException();
  }

  signed_ = true;
}
