#include "PmergeMe.hpp"
#include <exception>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: ./PmergeMe [positive integers]" <<std::endl;
		return 1;
	}
	try{
		PmergeMe test(&argv[1]);
		test.processData();
	}catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}