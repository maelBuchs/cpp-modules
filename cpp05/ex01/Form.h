#ifndef FORM_H
#define FORM_H

// #include "Bureaucrat.h"
#include <iostream>

class Bureaucrat;

class Form {
  public:
    Form();
    Form(std::string name,  int const sGrade,  int const xGrade);
    Form(const Form &form);
    ~Form();
    std::string const getName();
    bool getIsSigned();
    int getSGrade() const;
    int getXGrade() const;
    void beSigned(Bureaucrat bureaucrat);
    void beExecuted(Bureaucrat const &executor) const;
    virtual void execute(Bureaucrat const &executor) const;

  private:
    std::string const _name;
    bool              _isSigned;
    const int         _sGrade;
    const int         _xGrade;
    
    class GradeTooHighException : public std::exception {
      public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &o, Form &f);

#endif