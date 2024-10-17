#include "Bureaucrat.h"
#include "AForm.h"
#include "PresidentialPardonForm.h"

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

    return 0;
}