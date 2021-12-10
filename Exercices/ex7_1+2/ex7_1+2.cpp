/**
 * Commands for links to work
 * g++ -c Point.cpp
 * g++ Point.o ex7_1.cpp everytime this file is changed
 */
#include <iostream>
#include "Point.hpp"

using namespace std;
int main()
{
    Point pt(2.0f, 3.0f);
    pt.move(5.0f, 5.0f);

    // Show the coords of pt
    cout << "(" << pt.abscissa() << ", " << pt.ordinate() << ")" << endl;
}