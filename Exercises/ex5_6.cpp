#include <iostream>

using namespace std;

/**
 * @brief Swap place of first and last cells of an array
 * 
 * @param array array to swap the cells
 * @param size size of the array
 */
void permutation(int array[], size_t size)
{
    if (size > 1)
    {
        int temp = array[0];
        array[0] = array[size - 1];
        array[size - 1] = temp;
        for (size_t i = 0; i < size; ++i)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6};
    const size_t CAPACITY = sizeof(array) / sizeof(int);
    permutation(array, CAPACITY);
}