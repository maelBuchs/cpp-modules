#ifndef FILE_HPP
#define FILE_HPP

#include <fstream>
#include <iostream>
#include <string>
typedef std::string str;

class File {
  public:
    void setFilename(str fileName);
    str  getFilename();
    int  replace(str search, str found);
    File(str fileName);
    ~File();

  private:
    str _fileName;
};

#endif