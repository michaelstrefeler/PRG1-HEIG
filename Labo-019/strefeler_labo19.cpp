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
 * @brief Checks if all cells are in ascending order
 *
 * @param array the array to check
 * @param array_size the size of the array
 */
bool isAscendingOrder(const int array[], size_t array_size)
{
    for (size_t i = 0; i < array_size - 1; ++i)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Cout contents of table separated by spaces
 *
 * @param array the array we want to show
 * @param array_size the size of said array
 */
void showTableContents(const int array[], size_t array_size)
{
    for (size_t i = 0; i < array_size; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

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
    showTableContents(array, array_size);
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
    showTableContents(array, array_size);
}

/**
 * @brief Alternate addition and substraction of all elements of array
 *
 * @param array array we want to do the math with
 * @param array_size size of the array
 * @return int the alterating sum of the elements in the array
 */
int alternatingSum(const int array[], size_t array_size)
{
    int result = 0;
    for (size_t i = 0; i < array_size; ++i)
    {
        if (i % 2 == 0)
        {
            result += array[i];
        }
        else
        {
            result -= array[i];
        }
    }
    return result;
}

/**
 * @brief Find a value and return where it is
 * 
 * @param array array used
 * @param array_size size of array
 * @param value value we want
 * @param pos position
 * @return size_t 
 */
size_t findValue(int array[], size_t array_size, int value, size_t pos = 0)
{
    for (; pos < array_size; ++pos)
    {
        if (array[pos] == value)
            return pos;
    }
    return array_size;
}

/**
 * @brief Delete a value and keep order
 * 
 * @param array array used
 * @param array_size size of array
 */
void deleteKeepOrder(int array[], size_t &array_size)
{
    size_t pos = findValue(array, array_size, 2);

    if (pos < array_size)
    {
        for (size_t i = pos + 1; i < array_size; ++i)
        {
            array[i - 1] = array[i];
        }
        --array_size;
    }
}

int main()
{
    int array_one[] = {0, 1, 2, 3, 4, 5};
    const size_t CAPACITY_ONE = sizeof(array_one) / sizeof(int);
    size_t size_one = CAPACITY_ONE;
    int array_two[] = {0, 1, 2, 3, 4, 5, 6};
    const size_t CAPACITY_TWO = sizeof(array_two) / sizeof(int);
    size_t size_two = CAPACITY_TWO;

    int array_three[] = {1, 2, 3, 4};
    const size_t CAPACITY_THREE = sizeof(array_three) / sizeof(int);
    size_t size_three = CAPACITY_THREE;

    cout << "Move all cells right:" << endl;

    cout << "Before: ";
    showTableContents(array_one, size_one);

    cout << "After: ";
    moveRight(array_one, size_one);

    cout << "\nRemove middle of array" << endl;
    cout << "Even number of cells before: ";
    showTableContents(array_one, size_one);
    cout << "After: ";
    DeleteMiddle(array_one, size_one);
    cout << "Odd number of cells before: ";
    showTableContents(array_two, size_two);
    cout << "After: ";
    DeleteMiddle(array_two, size_two);

    cout << "\nCheck if array is strictly ascending:" << endl;
    showTableContents(array_one, size_one);
    cout << boolalpha << isAscendingOrder(array_one, size_one) << endl;

    showTableContents(array_two, size_two);
    cout << boolalpha << isAscendingOrder(array_two, size_two) << endl;

    cout << "\nAlternating sum of: ";
    showTableContents(array_three, size_three);
    cout << alternatingSum(array_three, size_three);

    cout << "\nFind and remove 2 from: ";
    showTableContents(array_three, size_three);
    deleteKeepOrder(array_three, size_three);
    showTableContents(array_three, size_three);
}