#ifndef CPP07_EX00_TEMPLATES_HPP
#define CPP07_EX00_TEMPLATES_HPP

template <typename T> const T& max(const T& a, const T& b)
{
    return (a > b) ? a : b;
}

template <typename T> const T& min(const T& a, const T& b)
{
    return (a < b) ? a : b;
}

template <typename T> void swap(T &a, T &b)
{
    T bucket(a);
    a = b;
    b = bucket;
}

#endif