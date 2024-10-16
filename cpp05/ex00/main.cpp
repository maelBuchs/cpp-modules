#include "Bureaucrat.h"

int main() {

    try {
        Bureaucrat b1("Jean", 150);
        std::cout << b1 << std::endl;

        b1.incrementGrade();
        std::cout << b1 << std::endl;

        b1.decrementGrade();
        std::cout << b1 << std::endl;
        b1.decrementGrade();
        // throws exception

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Jean2", 0);
        b2.incrementGrade(155);
    } catch (const std::exception &e) {

        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Jean240", 151);
        std::cout << b3 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    return 0;
}