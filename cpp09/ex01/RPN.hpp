#include <iostream>
#include <stack>

#define display(x) std::cout << x << std::endl

#define err_display(x) std::cout << "Error : " << x << std::endl

class RPN
{
    public:
        RPN();
        ~RPN();
        static int compute(std::string input);
    private:
};  