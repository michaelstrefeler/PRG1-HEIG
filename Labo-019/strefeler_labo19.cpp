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

    for (size_t i = array_size - 1; i > 0; --i)
    {
        array[i] = array[i - 1];
    }
    array[0] = right;

    cout << "Move right result:" << endl;
    for (size_t i = 0; i < array_size; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

/**
 * @brief Deletes middle cell of array or middle 2 cells if the size is even
 *
 * @param array array that will be modified
 * @param array_size size of the array
 */
void DeleteMiddle(int array[], size_t &array_size)
{
    size_t position;
    if (array_size % 2 == 0)
    {
        position = (array_size / 2) - 1;
        if (position < array_size)
        {
            for (int i = 0; i < 2; i++)
            {
                for (size_t i = position + 1; i < array_size; ++i)
                {
                    array[i - 1] = array[i];
                }
                --array_size;
            }
        }
    }
    else
    {
        position = (array_size / 2);
        if (position < array_size)
        {
            for (size_t i = position + 1; i < array_size; ++i)
            {
                array[i - 1] = array[i];
            }
            --array_size;
        }
    }

    cout << "Delete middle result:" << endl;
    for (size_t i = 0; i < array_size; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int array_one[] = {0, 1, 2, 3, 4, 5};
    const size_t CAPACITY_ONE = sizeof(array_one) / sizeof(int);
    size_t size_one = CAPACITY_ONE;
    int array_two[] = {0, 1, 2, 3, 4, 5, 6};
    const size_t CAPACITY_TWO = sizeof(array_two) / sizeof(int);
    size_t size_two = CAPACITY_TWO;
    moveRight(array_one, size_one);
    DeleteMiddle(array_one, size_one);
    DeleteMiddle(array_two, size_two);
}