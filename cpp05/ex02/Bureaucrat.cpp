#include "Bureaucrat.h"
#include "AForm.h"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
    : _name(bureaucrat._name),
      _grade(bureaucrat._grade) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bureaucrat) {
    _grade = bureaucrat._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string const Bureaucrat::getName() { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::incrementGrade(int n) {
    if (_grade - n < 1)
        throw GradeTooHighException();
    _grade -= n;
}

void Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::decrementGrade(int n) {
    if (_grade + n > 150)
        throw GradeTooLowException();
    _grade += n;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &f) {
    o << f.getName() << ", bureaucrat grade " << f.getGrade();
    return o;
}
const char *Bureaucrat::GradeTooHighException::what() const throw() { return "Grade is too high"; }

const char *Bureaucrat::GradeTooLowException::what() const throw() { return "Grade is too low"; }

void Bureaucrat::signForm(AForm *form) {

    if (form->getIsSigned())
    {
        std::cout << _name << " couldn't sign " << form->getName() << " beacause : already signed"
                  << std::endl;
        return;
    }
    try {
        form->beSigned(*this);
        std::cout << _name << " signs " << form->getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << _name << " couldn't sign " << form->getName() << " because : " << e.what()
                  << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) {
    try {
        form.execute(*this);
        std::cout << _name << " executes " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << _name << " couldn't execute " << form.getName() << " because : " << e.what()
                  << std::endl;
    }
}
