#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <stdexcept>
// #include "Form.h"
class Form;

class Bureaucrat {
  public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &bureaucrat);
    Bureaucrat &operator=(Bureaucrat const &bureaucrat);
    ~Bureaucrat();
    class GradeTooHighException : public std::exception {
      public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public:
        const char *what() const throw();
    };

    std::string const getName();
    int               getGrade() const;
    void              incrementGrade();
    void              incrementGrade(int n);
    void              decrementGrade();
    void              decrementGrade(int n);
    void signForm(Form *form);

    // Bureaucrat       &operator<<(Bureaucrat &bureaucrat);

  private:
    std::string const _name;
    int               _grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &f);

#endif