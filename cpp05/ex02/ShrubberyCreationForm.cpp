#include "ShrubberyCreationForm.h"
#include "AForm.h"
#include <ostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 25, 5),
      _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &a) {
    AForm::operator=(a);
    _target = a._target;
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &a) : AForm(a) {
    *this = a;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > getXGrade())
        throw GradeTooLowException();
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file.is_open()) {
        throw std::ios_base::failure("Error: Unable to open the file.");
    }

    file << "       _-_\n"
            "    /~~   ~~\\\n"
            " /~~         ~~\\\n"
            "{               }\n"
            " \\  _-     -_  /\n"
            "   ~  \\\\ //  ~\n"
            "_- -   | | _- _\n"
            "  _ -  | |   -_\n"
            "      // \\\\"
         << std::endl;
    file.close();
}