#ifndef AFORM_H
#define AFORM_H

#include <iostream>

class Bureaucrat;

class AForm {
  public:
    virtual ~AForm();
    std::string getName() const;
    bool getIsSigned();
    int getSGrade() const;
    int getXGrade() const;
    void beSigned(Bureaucrat bureaucrat);
    void beExecuted(Bureaucrat const &executor) const;
    virtual void execute(Bureaucrat const &executor) const = 0;
    AForm &operator=(AForm const &a);
    class GradeTooHighException : public std::exception {
      public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public:
        const char *what() const throw();
    };

  protected :
    AForm();
    AForm(std::string name,  int const sGrade,  int const xGrade);
    AForm(const AForm &Aform);
  
  private:
    std::string const _name;
    bool              _isSigned;
    const int         _sGrade;
    const int         _xGrade;
    
};

std::ostream &operator<<(std::ostream &o, AForm &f);

#endif