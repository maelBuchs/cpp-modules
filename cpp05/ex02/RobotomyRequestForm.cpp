#include "RobotomyRequestForm.h"
#include "AForm.h"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 25, 5), _target(target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &a)
{
	AForm::operator=(a);
	_target = a._target;
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &a) : AForm(a)
{
	*this = a;
}


void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if(executor.getGrade() > getXGrade())
		throw GradeTooLowException();
	if(rand() % 2)
		std::cout << _target << " has been robotomized." << std::endl;
	else
		std::cout << _target << " robotomization failed." << std::endl;
}