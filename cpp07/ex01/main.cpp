#include "iter.hpp"

int increment(int n)
{
  return n+2;
}

float increment2(float n)
{
  return n +2;
}

int main(void) {
  int array[5] = {1,2,3,4,5};
  float array2[5] = {1,2,3,4,5};
  for (int i = 0; i < 5; i++)
  {
    std::cout << "int before iter : " << array[i] << std::endl;
    std::cout << "float before iter : " << array2[i] << std::endl;

  }
  ::iter(array, 5, &increment);
  ::iter(array2, 5, &increment2);
  for (int i = 0; i < 5; i++)
  {
    std::cout << "int after iter : " << array[i] << std::endl;
    std::cout << "float after iter : " << array2[i] << std::endl;
  }
  return 0;
}