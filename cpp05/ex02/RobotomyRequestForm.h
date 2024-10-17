#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H




#include "AForm.h"
#include "Bureaucrat.h"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &a);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &a);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const &executor) const;

    private:
        std::string _target;
};

#endif