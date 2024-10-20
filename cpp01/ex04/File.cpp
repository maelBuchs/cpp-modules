#include "File.hpp"


void File::setFilename(str fileName) { _fileName = fileName; }

str File::getFilename() { return (_fileName); }

static int checkIsSearched(str search, str string, int i) {
    int j = 0;
    while (i + j <= int(string.length()) && j < int(search.length())) {
        if (string[i + j] == search[j])
            j++;
        else
            return 0;
    }
    return 1;
}

int File::replace(str search, str found) {
    std::ifstream infile(_fileName.c_str());
    if (!infile.is_open()) {
        std::cout << "Error could not open file : " << _fileName << std::endl;
        return 1;
    }

    std::ofstream outfile((_fileName + ".replace").c_str());
    if (!infile.is_open()) {
        std::cout << "Error could not create file : " << _fileName + ".replace" << std::endl;
        infile.close();
        return 1;
    }
    str line;
    while (std::getline(infile, line)) {
        str newLine;
        for (int i = 0; i <= int(line.length()); i++) {
            if (line[i] == search[0] && line.length() > search.length() + i - 1) {
                if (checkIsSearched(search, line, i)) {
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

File::File(str fileName) { setFilename(fileName); }

File::~File() { return; }