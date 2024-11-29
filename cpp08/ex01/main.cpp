#include "Span.h"
#include <iostream>

int main()
{
    Span sp = Span(5);


    sp.addNumber(1);
    sp.addNumber(2);
    sp.addNumber(3);
    sp.addNumber(4);
    sp.addNumber(5);
try{
    sp.addNumber(6);
    std::cout << sp << std::endl;

}catch(...)
{
    std::cout << "ERROR :: stack is full" << std::endl;
}
    std::cout << sp << std::endl;
}