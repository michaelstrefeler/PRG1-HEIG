/**
 * Commands for links to work
 * g++ -c Point.cpp 
 * g++ Point.o ex7_1.cpp everytime this file is changed
 */
#include "Point.hpp"

int main()
{
    Point pt(2.0f, 3.0f);
    pt.move(5.0f, 5.0f);
    pt.show();
}