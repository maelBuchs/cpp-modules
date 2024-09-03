#include <fstream>
#include <iostream>
#include <string>

typedef std::string str;

int checkIsSearched(str search, str string, int i)
{
  int j = 0;
  while (i + j <= string.length() && j < search.length() )
      {
        if (string[i + j] == search[j])
          j++;
        else
          return 0;
      }
      return 1;
}

str replace(str string, str search, str found)
{
  str replacedStr;
  int nbr = 0;

  for (int i = 0; i <= (string.length()); i++)
  {
    if (string[i] == search[0] && string.length() > search.length() + i - 1)
    {
      std::cout << "str i == " << string[i] << std::endl;
      if (checkIsSearched(search, string, i))
      {
        i += search.length();
        replacedStr.append(found);
      }
    }
    replacedStr.push_back(string[i]);
  }
  return replacedStr;
}

int main(int argc, char** argv)
{
  str replaced = replace(argv[1], argv[2], argv[3]);

  std::cout << "replaced = \"" << replaced << "\"" << std::endl;
}