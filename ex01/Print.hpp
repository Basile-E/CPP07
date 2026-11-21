#ifndef CPP07_EX01_PRINT_HPP
#define CPP07_EX01_PRINT_HPP

#include <iostream>

template<typename T> void Print(const T &thing)
{
    std::cout << thing << std::endl;
}

#endif
