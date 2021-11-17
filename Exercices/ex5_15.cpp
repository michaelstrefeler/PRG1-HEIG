/**
 * @file ex5_15.cpp
 * @author Michael Strefeler
 * @brief Checks if all elements in vector are odd
 * @version 0.1
 * @date 17-11-2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Checks if all elements are odd
 * 
 * @param v vector to use
 * @return true if all elements are odd
 * @return false if at least one element is even
 */
bool allOdd(const vector<int>& v)
{
    for (int i : v)
        if (i % 2 == 0)
            return false;
    return true;
}

int main()
{
    cout << boolalpha << allOdd({1, 3, 5}) << endl;
    cout << boolalpha << allOdd({1, 2, 3, 5}) << endl;
    cout << boolalpha << allOdd({}) << endl;
}