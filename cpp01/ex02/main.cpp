#include <iostream>

int main (int argc, char *argv[]) {

  std::string string = "HI THIS IS BRAIN";
  std::string &stringREF = string;
  std::string *stringPTR = &string;

  std::cout << &string <<std::endl;
  std::cout << stringPTR << std::endl;
  std::cout << &stringREF << std::endl;


  std::cout << string <<std::endl;
  std::cout << *stringPTR << std::endl;
  std::cout << stringREF << std::endl;

}