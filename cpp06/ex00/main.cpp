#include "ScalarConverter.h"

int main(){
	ScalarConverter::convert("0");
  ScalarConverter::convert("42.00f00001f");
  ScalarConverter::convert("42");
  ScalarConverter::convert("42.0f");
  ScalarConverter::convert("1.f");
}