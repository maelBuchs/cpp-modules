#ifndef FILE_HPP
#define FILE_HPP

#include <fstream>
#include <iostream>
#include <string>

class File {
  public:
    void setFilename(std::string fileName);
    std::string  getFilename();
    int  replace(std::string search, std::string found);
    File(std::string fileName);
    ~File();

  private:
    std::string _fileName;
};

#endif