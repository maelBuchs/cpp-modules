#include "Bureaucrat.h"
#include "AForm.h"
#include "PresidentialPardonForm.h"
#include "ShrubberyCreationForm.h"

int main(){
    try {
        Bureaucrat b1("Jean", 7);
        std::cout << b1 << std::endl;


        PresidentialPardonForm f1("bernard");
        b1.signForm(&f1);
        std::cout << f1 << std::endl;
        std::cout << b1 << std::endl;
        b1.signForm(&f1);
        std::cout << f1 << std::endl;
        b1.executeForm(f1);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try{
        Bureaucrat b2("Fred", 1);
        std::cout << b2 << std::endl;

        ShrubberyCreationForm f2("Billy");

        b2.executeForm(f2);
        b2.signForm(&f2);
        b2.executeForm(f2);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
