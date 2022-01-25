/**
 * @file ex5_7.cpp
 * @author Michael Strefeler
 * @brief Exercise 5.7 
 * @version 0.1
 * @date 12-11-2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

using namespace std;

/**
 * @brief Replace all even values with a specified value
 *
 * @param array array to modify
 * @param size size of the array
 */
void replaceEvenNumbers(int array[], size_t size, int value)
{
    if (size)
    {
        for (size_t i = 0; i < size; ++i)
        {
            if (array[i] % 2 == 0)
                array[i] = value;
            cout << array[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6};
    const size_t CAPACITY = sizeof(array) / sizeof(int);
    replaceEvenNumbers(array, CAPACITY, 69);
}