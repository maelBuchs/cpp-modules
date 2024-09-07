#include "File.hpp"

void File::setFilename(str fileName)
{
  _fileName = fileName;
}

str File::getFilename()
{
  return (_fileName);
}

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

int File::replace(str search, str found)
{
  std::ifstream infile(_fileName);
  std::ofstream outfile(_fileName + ".replace");
  str line;
  while (std::getline(infile, line))
  {
    str newLine;
    for (int i = 0; i <= (line.length()); i++)
    {
      if (line[i] == search[0] && line.length() > search.length() + i - 1)
      {
        std::cout << "str i == " << line[i] << std::endl;
        if (checkIsSearched(search, line, i))
        {
          i += search.length();
          newLine.append(found);
        }
      }
      newLine.push_back(line[i]);
    }
    outfile << newLine << std::endl;
  }
  outfile.close();
  infile.close();

  return 0;
}

File::File(str fileName)
{
  setFilename(fileName);
}

File::~File()
{
  return ;
}