/**
 * @file strefeler_labo20.cpp
 * @author Michael Strefeler
 * @brief Calculate factorial of n using an array. n! less than 500 digits
 * Each cell of the array is a digit. The array has 500 cells.
 * @version 0.1
 * @date 16-11-2021
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>

using namespace std;

/**
 * @brief Uses an array to calculate n! each cell is a digit
 * 
 * @param array array to use
 * @param size size of the array
 * @param number number used for factorial
 */
void factorialWithArray(int array[], size_t size, int number)
{
    int temp = 0;
    for (size_t i = size - 1; i > 0; --i)
    {
        array[i] = array[i] * number + temp;
        temp = 0;

        if (array[i] > 9)
        {
            temp = array[i] / 10;
            array[i] %= 10;
        }
    }
}

const int MAX_NUMBER = 252; // 252! has 498 digits and 253 has 500
const size_t SIZE = 500;

int main()
{
    int array[SIZE] = {};
    array[SIZE-1] = 1;
    int number = 0;
    size_t size = SIZE;

    cout << "Give me an integer in this interval[0, 252]: ";
    cin >> number;
    while (number < 0 or number > MAX_NUMBER)
    {
        cout << "Give me an integer in this interval[0, 252]: ";
        cin >> number;
        cin.clear();
    }

    // Loop to run the function until we reach the value the user entered
    for (int i = 1; i <= number; ++i)
    {
        factorialWithArray(array, size, i);
    }

    bool found_zero = false;
    // Show the value without a bunch of zeroes before it
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] > 0 and found_zero == false)
        {
            found_zero = true;
        }
        if (found_zero)
        {
            cout << array[i];
        }
    }
}