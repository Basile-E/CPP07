#ifndef CPP07_EX01_ITER_HPP
#define CPP07_EX01_ITER_HPP

template<typename T> void iter(T *arr, const int length, void (*function)(T&))
{
    for (int i = 0; i < length; i++)
    {
        function(arr[i]);
    }
}

template<typename T> void iter(const T *arr, const int length, void (*function)(const T&))
{
    for (int i = 0; i < length; i++)
    {
        function(arr[i]);
    }
}

#endif
