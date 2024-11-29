#include "easyfind.h"
#include <list>
#include <vector>

int main(void) {
  try {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << *easyfind(vec, 1) << std::endl;
    std::cout << *easyfind(vec, 2) << std::endl;
    std::cout << *easyfind(vec, 3) << std::endl;
    std::cout << *easyfind(vec, 5) << std::endl;
  } catch (...) {
    std::cout << "Error : Element isnt in the container" << std::endl;
  }

  try {
    std::list<int> lis;

    lis.push_back(3);
    lis.push_back(12);
    lis.push_back(6);
    lis.push_back(5);
    lis.push_back(4);

    lis.push_back(2);
    std::cout << *easyfind(lis, 5) << std::endl;
    std::cout << *easyfind(lis, 12) << std::endl;
    std::cout << *easyfind(lis, 6) << std::endl;
    std::cout << *easyfind(lis, 4) << std::endl;
    std::cout << *easyfind(lis, 20000) << std::endl;
  } catch (...) {
    std::cout << "Error : Coundnt find the element in the container"
              << std::endl;
  }
}