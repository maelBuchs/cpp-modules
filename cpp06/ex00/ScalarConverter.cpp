#include "ScalarConverter.h"
#include <cmath>
#include <iomanip>
#include <limits>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
  *this = other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  (void)other;
  return *this;
}

static void convertChar(double value) {

  char charValue = static_cast<char>(value);

  if (value != charValue || charValue < 31 || charValue == 127)
    throw ScalarConverter::InvalidInput();
  std::cout << "'" << charValue << "'" << std::endl;
}

static void convertInt(double value) {
  int intValue = static_cast<int>(value);

  if (value != intValue)
    throw ScalarConverter::InvalidInput();
  std::cout << intValue << std::endl;
}

static void convertFloat(float value) {

  float floatValue = static_cast<float>(value);

  if (std::isnan(floatValue) || std::isinf(floatValue)) {
    std::cout << floatValue << 'f' << std::endl;
    return;
  }

  if (value != floatValue)
    throw ScalarConverter::InvalidInput();
  if (floatValue - static_cast<int>(value))
    std::cout << std::setprecision(10) << floatValue << 'f' << std::endl;
  else
    std::cout << std::fixed << std::setprecision(1) << floatValue << 'f'
              << std::endl;
}

const char *ScalarConverter::InvalidInput::what() const throw() {
  return "Invalid Input";
}

static double checkSpecialCases(std::string input) {
  if (input == "inf" || input == "+inf" || input == "inff" || input == "+inff")
    return std::numeric_limits<double>::infinity();
  if (input == "-inf" || input == "-inff")
    return -std::numeric_limits<double>::infinity();
  if (input == "NaN" || input == "nan" || input == "nanf")
    return std::numeric_limits<double>::quiet_NaN();
  return 0;
}

static double atod(std::string input) {
  double value = checkSpecialCases(input);
  if (value != 0)
    return value;
  int i = 0;
  int decimal = 1;
  int isNeg = 0;

  if (input[0] == '-') {
    isNeg = 1;
    i++;
  }

  while (i < (int)input.length() && isdigit(input[i])) {
    value *= 10;
    value += input[i] - '0';
    i++;
  }
  if (i == 0 || (input[i] && input[i] != '.' && !(input[i] == 'f' && i + 1 == (int)input.length())) )
    throw ScalarConverter::InvalidInput();
  i++;

  while (i < (int)input.length() && isdigit(input[i])) {
    value += (input[i] - '0') * std::pow(10, -decimal);
    i++;
    decimal++;
  }
  if (i + 1 < (int)input.length() ||
      (i + 1 == (int)input.length() && input[i] != 'f' && !isdigit(input[i])))
    throw ScalarConverter::InvalidInput();

  if (isNeg)
    return -value;
  return value;
}

//TODO - check copy constructor and  overload

void ScalarConverter::convert(std::string input) {

  double value;
  try {
    value = atod(input);
  } catch (const std::exception &e) {
    std::cout << "Invalid input" << std::endl;
    return;
  }

  std::cout << "char: ";
  try {
    convertChar(value);
  } catch (const std::exception &e) {
    std::cout << "Non Displayable" << std::endl;
  }

  std::cout << "int: ";
  try {
    convertInt(value);
  } catch (const std::exception &e) {
    std::cout << "Invalid" << std::endl;
  }

  std::cout << "float: ";
  try {
    convertFloat(value);
  } catch (const std::exception &e) {
    std::cout << "error" << std::endl;
  }

  std::cout << "double: ";
  if (value - static_cast<int>(value))
    std::cout << std::setprecision(10) << value << std::endl;
  else
    std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}