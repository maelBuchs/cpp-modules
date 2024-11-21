#pragma once

#include <iostream>
#include <stdint.h>

typedef struct s_Data
{
  std::string name;
  std::string lastName;
  int age;
  
} Data;

class Serializer {
  private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &other);
  public:
    static uintptr_t serialize(Data* ptr);
    static Data *deserialize(uintptr_t raw);
};

// void autresFonctions();
