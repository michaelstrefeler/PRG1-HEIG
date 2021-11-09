/**
 * @file strefeler_labo19.cpp
 * @author Michael Strefeler
 * @brief Exercises 5.8 to 5.12
 * @version 0.1
 * @date 09-11-2021
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>

using namespace std;

/**
 * @brief Move all elements of an array to the right
 * 
 * @param array array used
 * @param array_size size of the array
 */
void moveRight(int array[], size_t array_size)
{
    int right = array[array_size - 1];

    for (size_t i = array_size - 1; i > 0; --i){
        array[i] = array[i - 1];
    }
    array[0] = right;

    for (size_t i = 0; i < array_size; ++i)
    {
        cout << array[i] << " ";
    }
}

int main()
{
    int array[] = {0, 1, 2, 3, 4, 5};
    size_t tab_size = sizeof(array) / sizeof(array[0]);
    moveRight(array, tab_size);
}