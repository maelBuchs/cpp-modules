#include "RPN.hpp"
#include <exception>

RPN::RPN() {}
RPN::~RPN() {}

static int isToken(char c) {
  if (c == '+' || c == '-' || c == '/' || c == '*')
    return 1;
  return 0;
}

static void calculate(char c, std::stack<int> *stack) {
  if (stack->size() < 2)
    throw(RPN::MissingNumber());
  int tmp = stack->top();
  stack->pop();
  if (c == '+')
    tmp += stack->top();
  if (c == '-')
    tmp -= stack->top();
  if (c == '/') {
    if (stack->top() == 0)
      throw(RPN::DividedByZero());
    tmp /= stack->top();
  }
  if (c == '*')
    tmp *= stack->top();
  stack->pop();
  stack->push(tmp);
  return;
}

int RPN::compute(std::string input) {

  std::stack<int> stack;

  input.erase(0, input.find_first_not_of(' '));

  for (int i = 0; i < (int)input.length(); i++) {
    if (isdigit(input[i]) && (input[i + 1] == ' ' || input[i + 1] == 0))
      stack.push(input[i] - '0');
    else if (isToken(input[i]) && i > 1 &&
             (input[i + 1] == ' ' || input[i + 1] == 0))
      calculate(input[i], &stack);
    else if (input[i] == ' ' || i == (int)input.length() - 1)
      continue;
    else
      throw(RPN::InvalidInput());
  }
  if (stack.size() > 1)
    throw(RPN::MissingNumber());
  return stack.top();
}

const char *RPN::DividedByZero::what() const throw() {
  return "Cannot divide by 0!";
}
const char *RPN::MissingNumber::what() const throw() {
  return "Too many/not enough token/number";
}
const char *RPN::InvalidInput::what() const throw() { return "Invalid Inupt"; }
