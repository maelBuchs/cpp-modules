#include "Span.h"

int main()
{
    Span sp = Span(100001);


    std::vector<int> vec;

try{
    std::cout << sp << std::endl;
    for(int i =0; i < 100000; i++)
        vec.push_back(i);
    sp.addMultiple(vec.begin(),vec.end());

}catch(...)
{
    std::cout << "ERROR :: stack is full" << std::endl;
}
    std::cout << sp << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
}


// int main()
// {
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }