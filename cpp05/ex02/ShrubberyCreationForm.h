#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H



#include "AForm.h"
#include "Bureaucrat.h"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &a);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &a);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const &executor) const;

    private:
        std::string _target;
};

#endif