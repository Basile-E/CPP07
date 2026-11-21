#include <iostream>
#include "iter.hpp"
#include "Print.hpp"

void increment(int &value)
{
    ++value;
}

int main()
{
    int values[] = {1, 2, 3};
    iter(values, 3, Print);
    iter(values, 3, increment);
    iter(values, 3, Print);

    const int readOnlyValues[] = {4, 5, 6};
    iter(readOnlyValues, 3, Print);
}