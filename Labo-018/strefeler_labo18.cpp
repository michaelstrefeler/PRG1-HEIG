/**
 * @file strefeler_labo18.cpp
 * @author Michael Strefeler
 * @brief Maclaurin series to determine sin of x
 * @version 0.1
 * @date 08-11-2021
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <cmath>
#include <iostream>

using namespace std;
const double PI = atan2(0, -1);

/**
 * @brief Get factorial of number
 * 
 * @param number  
 * @return long double 
 */
long double factorial(long double number)
{
    if (number <= 1)
        return 1;
    else
        return number * factorial(number - 1);
}

/**
 * @brief maclaurin series to find sin of a number
 * 
 * @param number 
 * @return long double 
 */
long double maclaurin(double number){
    int i = 0;
    long double result = 0.0;

    // infinite sum not possible so sum 100 instead
    while(i < 100){
        result += pow(-1, i) * (pow(number, 2*i+1)/(factorial(2 * i + 1)));
        i++;
    }
    return result;
}

int main()
{   
    double input;
    cout << "Give me a double in degrees : ";
    cin >> input;

    // convert deg to rad
    input = input * PI/180;
    cout << "Sin of x: " << maclaurin(input) << endl;
    cout << "sin of x using cmath : " << sin(input)<< endl;
}