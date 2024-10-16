#include "Bureaucrat.h"
#include "Form.h"

int main(){
    try {
        Bureaucrat b1("Jean", 11);
        std::cout << b1 << std::endl;


        Form f1("Form1", 10, 10);
        b1.signForm(&f1);
        std::cout << f1 << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;
        b1.signForm(&f1);
        std::cout << f1 << std::endl;
        
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}