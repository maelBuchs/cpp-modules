#include "ScalarConverter.h"

static void convertChar(char value) {}
static void convertInt(int value) {}
static void convertFloat(float value) {}
static void convertDouble(double value) {}

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {}

void ScalarConverter::convert(std::string input) {

    int type = getType();
    int value = getValue();

    std::cout << "char: ";
    try {
        convertChar(value);
    } catch (const std::exception &e) {
        std::cout << "error" << std::endl;
    }

    std::cout << "int: ";
    try {
        convertInt(value);
    } catch (const std::exception &e) {
        std::cout << "error" << std::endl;
    }

    std::cout << "float: ";
    try {
        convertFloat(value);
    } catch (const std::exception &e) {
        std::cout << "error" << std::endl;
    }

    std::cout << "double: ";
    try {
        convertDouble(value);
    } catch (const std::exception &e) {
        std::cout << "error" << std::endl;
    }
}