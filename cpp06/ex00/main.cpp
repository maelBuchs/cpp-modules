#include "ScalarConverter.h"

int main(int argc, char **argv){
	if(argc != 2)
  {
    std::cout << "Usage : ./ScalarConverter [value]" << std::endl;
    return -1;
  }
	ScalarConverter::convert(argv[1]);

}