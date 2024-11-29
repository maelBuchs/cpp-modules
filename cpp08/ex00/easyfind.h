#include <algorithm>
#include <iostream>

template <typename T> 

typename T::iterator easyfind(T &container, int n)
{
    typename T::iterator finded;
    finded = std::find(container.begin(),container.end(), n);
    if (finded == container.end())
        throw std::exception();
    return finded;
}
