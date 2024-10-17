#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.h"
#include "Bureaucrat.h"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &a);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &a);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const &executor) const;

    private:
        std::string _target;
};

#endif