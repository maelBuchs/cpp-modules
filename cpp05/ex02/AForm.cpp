#include "AForm.h"
#include "Bureaucrat.h"

const char *AForm::GradeTooHighException::what() const throw() { return "Grade is too high"; }

const char *AForm::GradeTooLowException::what() const throw() { return "Grade is too low"; }

AForm::AForm(std::string name, int const sGrade, int const xGrade)
    : _name(name),
      _isSigned(false),
      _sGrade(sGrade),
      _xGrade(xGrade) {
    if (sGrade > 150 || xGrade > 150)
        throw GradeTooLowException();
    if (sGrade < 1 || xGrade < 1)
        throw GradeTooHighException();
}

AForm::AForm(const AForm &Aform)
    : _name(Aform._name),
      _isSigned(Aform._isSigned),
      _sGrade(Aform._sGrade),
      _xGrade(Aform._xGrade) {}

AForm::~AForm() {}

std::string AForm::getName() const { return _name; }

bool AForm::getIsSigned() { return _isSigned; }

int AForm::getSGrade() const { return _sGrade; }

int AForm::getXGrade() const { return _xGrade; }

void AForm::beSigned(Bureaucrat bureaucrat) {
    if (bureaucrat.getGrade() > _sGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &o, AForm &f) {
    o << f.getName() << ", needs a " << f.getSGrade() << " grade to sign and a " << f.getXGrade()
      << " grade to execute." << std::endl;
    if (f.getIsSigned())
        o << "It is signed.";
    else
        o << "It is not signed.";
    return o;
}

AForm &AForm::operator=(AForm const &a) {
    _isSigned = a._isSigned;
    return (*this);
}
