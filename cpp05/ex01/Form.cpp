#include "Form.h"
#include "Bureaucrat.h"

const char *Form::GradeTooHighException::what() const throw() { return "Grade is too high"; }

const char *Form::GradeTooLowException::what() const throw() { return "Grade is too low"; }

Form::Form(std::string name, int const sGrade, int const xGrade)
    : _name(name),
      _isSigned(false),
      _sGrade(sGrade),
      _xGrade(xGrade) {
    if (sGrade > 150 || xGrade > 150)
        throw GradeTooLowException();
    if (sGrade < 1 || xGrade < 1)
        throw GradeTooHighException();
}

// Form(const Form &form);
Form::~Form() {}

std::string const Form::getName() { return _name; }

bool Form::getIsSigned() { return _isSigned; }

int Form::getSGrade() const { return _sGrade; }

int Form::getXGrade() const { return _xGrade; }

void Form::beSigned(Bureaucrat bureaucrat) {
    if (bureaucrat.getGrade() > _sGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &o, Form &f) {
    o << f.getName() << ", needs a " << f.getSGrade() << " grade to sign and a " << f.getXGrade()
      << " grade to execute." << std::endl;
    if (f.getIsSigned())
        o << "It is signed.";
    else
        o << "It is not signed.";
    return o;
}