#ifndef SCALAR_CONVERTER
#define SCALAR_CONVERTER

#include <iostream>

enum {
  CHAR,
  INT,
  FLOAT,
  DOUBLE,
  INVALID
};

class ScalarConverter {
  private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
  public:
    static void convert(std::string input);
    class InvalidInput : public std::exception {
      public:
        const char *what() const throw();
    };
};

// void autresFonctions();

#endif