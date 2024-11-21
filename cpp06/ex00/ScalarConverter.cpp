#include "ScalarConverter.h"
#include <cmath>
#include <iomanip>



// static void convertChar(char value) {}
// static void convertInt(int value) {}
// static void convertFloat(float value) {}
// static void convertDouble(double value) {}
const char *ScalarConverter::InvalidInput::what() const throw() { return "Grade is too high"; }

static double atod(std::string input, int type) {
    double value = 0.00000;
    //Int part
    
    (void) type;
    int i = 0;
    int decimal = 1;

    std::cout << "\n\nString = " << input << std::endl;
    while(i < (int)input.length() && isdigit(input[i]))
    {
        value *= 10;
        value += input[i] - '0';
        i++;
    }
    if((input[i] && input[i] != '.') || i == 0)
        throw ScalarConverter::InvalidInput();
    i++;
    
    //Decimal part
    while(i < (int)input.length() && isdigit(input[i]))
    {
        value += (input[i] - '0') * std::pow(10,-decimal); 
        i++;
        decimal++;
    }
    if (i + 1 < (int)input.length() || (i + 1 == (int)input.length() && input[i] != 'f' && !isdigit(input[i])))
        throw ScalarConverter::InvalidInput();

    std::cout << std::setprecision(10) << "Full part = " << value << std::endl;
        
    return value;
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { *this = other;}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void) other; 
return *this;}

void ScalarConverter::convert(std::string input) {

    int type = FLOAT;
    double value;
    try{
        value = atod(input, type);
    }catch(const std::exception &e){
        std::cout << "Invalid input" << std::endl;
        return ;
    }

    // std::cout << "char: ";
    // try {
    //     convertChar(value);
    // } catch (const std::exception &e) {
    //     std::cout << "error" << std::endl;
    // }

    // std::cout << "int: ";
    // try {
    //     convertInt(value);
    // } catch (const std::exception &e) {
    //     std::cout << "error" << std::endl;
    // }

    // std::cout << "float: ";
    // try {
    //     convertFloat(value);
    // } catch (const std::exception &e) {
    //     std::cout << "error" << std::endl;
    // }

    // std::cout << "double: ";
    // try {
    //     convertDouble(value);
    // } catch (const std::exception &e) {
    //     std::cout << "error" << std::endl;
    // }
}