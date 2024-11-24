#pragma once

#include <iostream>
#include <stdint.h>


class Base {
  public:
    Base();
    ~Base();
  private:
};


Base *generate(void);

void identify(Base *p);

void identify(Base &p);

// void autresFonctions();
