#include <iostream>
#include <string>
#include "Array.hpp"

bool throwsAt(Array<int>& array, unsigned int index)
{
    try
    {
        (void)array[index];
    }
    catch (const std::exception&)
    {
        return true;
    }
    return false;
}

int main()
{
    Array<int> empty;
    if (empty.size() != 0 || !throwsAt(empty, 0)
        || !throwsAt(empty, static_cast<unsigned int>(-1)))
        return 1;

    Array<int> values(3);
    if (values.size() != 3 || values[0] != 0 || values[1] != 0 || values[2] != 0)
        return 2;
    values[0] = 10;
    values[1] = 20;
    values[2] = 30;

    const Array<int>& constValues = values;
    if (constValues.size() != 3 || constValues[1] != 20)
        return 3;
    if (throwsAt(values, 3) == false
        || throwsAt(values, static_cast<unsigned int>(-1)) == false)
        return 4;

    Array<int> copied(values);
    copied[0] = 99;
    if (values[0] != 10)
        return 5;
    values[0] = 11;
    if (copied[0] != 99)
        return 5;
    values[0] = 10;

    Array<int> assigned(1);
    assigned[0] = -1;
    assigned = values;
    assigned[1] = 99;
    if (values[1] != 20)
        return 6;
    values[2] = 31;
    if (assigned[2] != 30)
        return 6;

    Array<int>* sameValues = &values;
    values = *sameValues;
    if (values[0] != 10 || values[1] != 20 || values[2] != 31)
        return 7;

    assigned = empty;
    if (assigned.size() != 0 || !throwsAt(assigned, 0))
        return 8;

    Array<std::string> words(2);
    words[0] = "first";
    words[1] = "second";
    Array<std::string> copiedWords(words);
    copiedWords[0] = "changed";
    if (words[0] != "first")
        return 9;

    std::cout << "All Array tests passed" << std::endl;
    return 0;
}