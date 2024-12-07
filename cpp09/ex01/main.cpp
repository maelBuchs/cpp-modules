#include "RPN.hpp"

int main(int argc, char **argv) {
  if (argc != 2)
  {
    if (argc > 2)
        err_display("too many argument");
    else
        err_display("missing argument");
    return 1;
  }

  try {
    int result = RPN::compute(argv[1]);
    display(result);
  } catch (const std::exception &e) {
    err_display(e.what());
    return 1;
  }
}