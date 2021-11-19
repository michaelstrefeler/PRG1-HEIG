/**
 * @file strefeler_labo21.cpp
 * @author Michael Strefeler
 * @brief Exercises 5.13 and 5.14
 * @version 0.1
 * @date 17-11-2021
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
using namespace std;
/**
 * @brief Shows all elements of an array in order
 *
 * @param array
 * @param size
 */
void showArray(int array[], size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

/**
 * @brief Remove duplicates
 *
 * @param array from this
 * @param size this big
 */
void removeDuplicates(int array[], size_t &size)
{
    showArray(array, size); // Before
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = i + 1; j < size;)
        {
            if (array[i] == array[j])
            {
                for (size_t k = j; k < size - 1; ++k)
                    array[k] = array[k + 1];
                --size;
            }
            else
                ++j;
        }
    }
    showArray(array, size); // After
}

bool equalArrays(int array[], int array_two[], size_t size, size_t size_two)
{
    showArray(array, size);
    showArray(array_two, size_two);
    bool equal = false;
    for (size_t i = 0; i < size; i++)
    {
        equal = false;
        for (size_t j = 0; j < size_two; j++)
        {
            if (array[i] == array_two[j])
            {
                equal = true;
                break;
            }
        }

        if (!equal)
        {
            return false;
        }
    }

    for (size_t i = 0; i < size_two; i++)
    {
        equal = false;
        for (size_t j = 0; j < size; j++)
        {
            if (array_two[i] == array[j])
            {
                equal = true;
                break;
            }
        }

        if (!equal)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // Variables and functions for exercise 5.13
    int array[] = {1, 2, 4, 2, 1, 1, 3};
    const size_t CAPACITY = sizeof(array) / sizeof(int);
    size_t size = CAPACITY;

    cout << "Exercise 5.13 Remove duplicates: " << endl;
    removeDuplicates(array, size);

    // Variables and functions for exercise 5.14
    int array_one[] = {3, 3, 1, 1, 2, 1};
    const size_t CAPACITY_ONE = sizeof(array_one) / sizeof(int);
    size_t size_one = CAPACITY_ONE;
    int array_two[] = {1, 2, 3, 4};
    const size_t CAPACITY_TWO = sizeof(array_two) / sizeof(int);
    size_t size_two = CAPACITY_TWO;
    cout << "\nExercise 5.14 same elements in 2 arrays: " << endl;
    cout << boolalpha << equalArrays(array_one, array_two, size_one, size_two);
}