/**
 * Commands for links to work
 * g++ -c Point.cpp
 * g++ Point.o main.cpp everytime this file is changed
 */
#include <iostream>
#include "Point.hpp"

using namespace std;
int main()
{
    Point pt(2.0f, 3.0f);
    Point pt2(1.0f, 67.0f);
    pt = pt2;
    pt.move(5.0f, 5.0f);
    
    cout << Point(5.0f, 5.0f).abscissa() << " " << pt2.ordinate() << endl;
    const Point pt3 = pt + pt2;
    cout << pt3.abscissa() << " " << pt3.ordinate() << endl;
    Point pt4 = pt3 + Point(2.0f, 3.0f);
    cout << pt4.abscissa() << " " << pt4.ordinate() << endl;
    cout << pt2.rho() << " " << pt2.theta() << endl;
    pt = Point(3.0f, 0.0f);
    for(int i = 0; i <= 8; ++i){
        pt.rotation(PI/4.0f);
        cout << pt.abscissa() << " " << pt.ordinate() << endl;
    }
}