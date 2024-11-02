#include "ScalarConverter.h"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {}

void ScalarConverter::convert(std::string input) {

  int type = getType();
  int value = getValue();
  switch (value)
  {
    case CHAR:
      //convertChar();
    case INT:
      // convertInt();
    case FLOAT:
      // convertFloat();
    case DOUBLE:
      // convertDouble();
    default :
      std::cout << "invalid input" << std::endl;
  }
}