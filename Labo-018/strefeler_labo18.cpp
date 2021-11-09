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

#include <chrono>
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
    long double result = 1.0;
    for(long double i = number; i > 0; i--){
        result *= i;
    }
    return result;
}

/**
 * @brief maclaurin series to find sin of a number
 *
 * @param number
 * @return long double
 */
long double maclaurin(double number)
{
    int i = 0;
    long double result = 0.0;

    // infinite sum not possible so sum 100 instead
    while (i < 1000)
    {
        result += pow(-1, i) * (pow(number, 2 * i + 1) / (factorial(2 * i + 1)));
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
    input = input * PI / 180;
    // start clock
    auto start = chrono::system_clock::now();
    cout << "Sin of x: " << maclaurin(input) << endl;
    // end clock
    auto end = chrono::system_clock::now();
    //calculate and output duration
    auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << elapsed.count() << "ms" << endl;

    // start second clock
    auto start_sin = chrono::system_clock::now();
    cout << "sin of x using cmath : " << sin(input) << endl;
    // end second clock
    auto end_sin = chrono::system_clock::now();
    // calculate and output second duration
    auto elapsed_sin = chrono::duration_cast<chrono::milliseconds>(end_sin - start_sin);
    cout << elapsed_sin.count() << "ms" << endl;
}