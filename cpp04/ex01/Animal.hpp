#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
class Animal {
public:
  Animal();
  Animal(std::string type);
  Animal(const Animal &src);
  Animal &operator=(const Animal &src);
  virtual ~Animal();
  std::string getType() const;
  void setType(std::string type);
  virtual void makeSound() const;

protected:
  std::string _type;
};

#endif