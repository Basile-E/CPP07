#ifndef CPP07_EX02_ARRAY_HPP
#define CPP07_EX02_ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template<typename T>
class Array
{
    public:
        Array();
        Array(unsigned int n);
        Array(const Array<T>& other);
        ~Array();

        Array<T>& operator=(const Array<T>& other);
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        unsigned int size() const;

    private:
        T* _arr;
        unsigned int _size;
};

template<typename T>
Array<T>::Array() : _arr(NULL), _size(0)
{
}

template<typename T>
Array<T>::Array(unsigned int n) : _arr(n ? new T[n]() : NULL), _size(n)
{
}

template<typename T>
Array<T>::Array(const Array<T>& other) : _arr(NULL), _size(other._size)
{
    if (_size)
    {
        _arr = new T[_size]();
        try
        {
            for (unsigned int i = 0; i < _size; ++i)
                _arr[i] = other._arr[i];
        }
        catch (...)
        {
            delete[] _arr;
            throw;
        }
    }
}

template<typename T>
Array<T>::~Array()
{
    delete[] _arr;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other)
    {
        T* newArr = NULL;
        if (other._size)
        {
            newArr = new T[other._size]();
            try
            {
                for (unsigned int i = 0; i < other._size; ++i)
                    newArr[i] = other._arr[i];
            }
            catch (...)
            {
                delete[] newArr;
                throw;
            }
        }
        delete[] _arr;
        _arr = newArr;
        _size = other._size;
    }
    return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Array index out of bounds");
    return _arr[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::out_of_range("Array index out of bounds");
    return _arr[index];
}

template<typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

#endif
