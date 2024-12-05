#include "RPN.hpp"
#include <exception>

RPN::RPN() {}
RPN::~RPN() {}

static int isToken(char c) {
  if (c == '+' || c == '-' || c == '/' || c == '*')
    return 1;
  return 0;
}

static int calculate(char c, std::stack<int> stack, int result) {

  if (c == '+')
    return result + stack.top();
  if (c == '-')
    return result - stack.top();
  if (c == '/') {
    if (stack.top() == 0)
      throw(std::exception());
    return result / stack.top();
  }
  if (c == '*')
    return result * stack.top();
  return result;
}

int RPN::compute(std::string input) {

  input.erase(0, input.find_first_not_of(' ')); 
  if (!isdigit(input[0]))
    throw(std::exception());
  int result = input[0] - '0';
  std::stack<int> stack;

  for (int i = 2; i < (int)input.length(); i++) {
    display(input[i]);
    if (isdigit(input[i]) && input[i + 1] == ' ')
      stack.push(input[i] - '0');
    else if (isToken(input[i]) && i > 1 &&
             (input[i + 1] == ' ' || input[i + 1] == 0)) {
      result = calculate(input[i], stack, result);
      stack.pop();
    } else if (input[i] == ' ' || i == (int) input.length()-1)
        continue;
    // else
    //   throw(std::exception());
  }
  if (stack.size() > 0)
    throw(std::exception());
  return result;
}