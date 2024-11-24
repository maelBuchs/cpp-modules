#pragma once

#include <iostream>

template <typename T>
void iter(T array[], int len, T(function)(T))
{
    for(int i = 0; i < len; i++)
        array[i] = function(array[i]);
}

