#include "PresidentialPardonForm.h"
#include "AForm.h"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &a)
{
	AForm::operator=(a);
	_target = a._target;
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &a) : AForm(a)
{
	*this = a;
}


void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if(executor.getGrade() > getXGrade())
		throw GradeTooLowException();
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}