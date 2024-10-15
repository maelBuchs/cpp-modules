#include "File.hpp"

typedef std::string str;

int main(int argc, char** argv)
{

  if (argc < 4)
    std::cout << "Error : Not enough arguments" << std::endl \
      << "./replacer [filename] [str1] [str2]" << std::endl;
  if (argc > 4)
    std::cout << "Error : Too many arguments" << std::endl << \
      "./replacer [filename] [str1] [str2]" << std::endl;
  if (argc != 4)
    return 1;  

  File File(argv[1]);
  File.replace(argv[2], argv[3]);
}