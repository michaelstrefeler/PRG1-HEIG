/**
 * @file ex6_7.cpp
 * @author Michael Strefeler
 * @brief Get the middle of a string
 * @version 0.1
 * @date 01-12-2021
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cout << "Give me a string ";
    cin >> str;
    string middle;
    if (str.length() % 2)
    {
        middle = str[str.length() / 2];
    }
    else
    {
        middle = str.substr((str.length() / 2) - 1, 2);
    }
    cout << "The middle is " << middle << endl;
}