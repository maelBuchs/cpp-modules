#include "A.h"
#include "B.h"
#include "C.h"
#include <cstdlib>
#include <ctime>

Base *generate(void) {
  std::srand(std::time(NULL));
  int randomNum = std::rand() % 3;
  std::cout << "rand = " << randomNum << std::endl;

  Base *randomClass;
  switch (randomNum) {
  case 0:
    randomClass = new A();
    break;

  case 1:
    randomClass = new B();
    break;

  case 2:
    randomClass = new C();
    break;
  }
  return randomClass;
}

void identify(Base *p) {
  if (A *castedA = dynamic_cast<A *>(p))
    std::cout << "This is a A type" << std::endl;
  else if (B *castedB = dynamic_cast<B *>(p))
    std::cout << "This is a B type" << std::endl;
  else if (C *castedC = dynamic_cast<C *>(p))
    std::cout << "This is a C type" << std::endl;
}

void identify(Base &p) {
  try {
    A &castedA = dynamic_cast<A &>(p);
    (void)castedA;
    std::cout << "This is a A type" << std::endl;
    return;
  } catch (...) {
  }

  try {
    B &castedB = dynamic_cast<B &>(p);
    (void)castedB;
    std::cout << "This is a B type" << std::endl;
    return;
  } catch (...) {
  }

  try {
    C &castedC = dynamic_cast<C &>(p);
    (void)castedC;
    std::cout << "This is a C type" << std::endl;
    return;
  } catch (...) {
  }
}

//TODO - Add A B and C constructor in Base.cpp

int main() {

  identify(generate());

  Base &test = *generate();

  identify(test);
}