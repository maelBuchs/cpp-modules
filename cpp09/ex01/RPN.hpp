#include <iostream>
#include <stack>

#define display(x) std::cout << x << std::endl

#define err_display(x) std::cout << "Error : " << x << std::endl

class RPN
{
    public:
        static int compute(std::string input);
    class DividedByZero : public std::exception {
      public:
        const char *what() const throw();
    };
    class MissingNumber : public std::exception {
      public:
        const char *what() const throw();
    };
    class InvalidInput : public std::exception {
      public:
        const char *what() const throw();
    };
    private:
        RPN();
        ~RPN();
};  