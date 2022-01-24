/**
 * @file ex5_18.cpp
 * @author Michael Strefeler
 * @brief Sum of values in left and right diag of square Matrix
 * @version 0.1
 * @date 19-11-2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Line;
typedef vector<Line> Matrix;

/**
 * @brief Sum the values of both diagonals of a square matrix
 * 
 * @param m 
 * @param left 
 * @param right 
 */
void sumDiagonals(Matrix m, int &left, int &right)
{
    size_t number_of_lines = m.size();
    left = right = 0;
    for (size_t i = 0; i < number_of_lines; i++)
    {
        left += m.at(i).at(i);
        right += m.at(i).at(number_of_lines - 1 - i);
    }
}

int main()
{
    Matrix m = {{1, 0, 1},
                {0, 1, 0},
                {1, 1, 0}};
    int left, right;
    sumDiagonals(m, left, right);
    cout << left << " " << right << endl;
}