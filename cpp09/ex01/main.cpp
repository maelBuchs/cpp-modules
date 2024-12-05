#include "RPN.hpp"

int main(int argc, char **argv)
{
    if(argc != 2)
        err_display("missing argument");
    try
    {
        int result = RPN::compute(argv[1]);
        display(result);
    }catch(...)
    {
        err_display("to define");
    }
}