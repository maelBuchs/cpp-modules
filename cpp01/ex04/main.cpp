#include "File.hpp"

typedef std::string str;

// int checkIsSearched(str search, str string, int i)
// {
//   int j = 0;
//   while (i + j <= string.length() && j < search.length() )
//       {
//         if (string[i + j] == search[j])
//           j++;
//         else
//           return 0;
//       }
//       return 1;
// }

// str replace(str string, str search, str found)
// {
//   str replacedStr;
//   int nbr = 0;

//   for (int i = 0; i <= (string.length()); i++)
//   {
//     if (string[i] == search[0] && string.length() > search.length() + i - 1)
//     {
//       std::cout << "str i == " << string[i] << std::endl;
//       if (checkIsSearched(search, string, i))
//       {
//         i += search.length();
//         replacedStr.append(found);
//       }
//     }
//     replacedStr.push_back(string[i]);
//   }
//   return replacedStr;
// }

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
  // str replaced = replace(argv[1], argv[2], argv[3]);
  // std::cout << "replaced = \"" << replaced << "\"" << std::endl;
}