/**
 * @file strefeler_labo22.cpp
 * @author Michael Strefeler
 * @brief Learn how to use vector methods and learn about Fibonacci
 * @version 0.1
 * @date 19-11-2021
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Add 2 vectors reprensenting long numbers where each element is a digit
 * 
 * @param v1 first vector
 * @param v2 second vector
 * @return vector<int> the sum of the two numbers
 */
vector<int> add(vector<int> v1, vector<int> v2)
{
    while (v1.size() > v2.size())
    {
        v2.insert(v2.begin(), 0);
    }

    while (v2.size() > v1.size())
    {
        v1.insert(v1.begin(), 0);
    }

    size_t size = v1.size();
    vector<int> sum;
    sum.resize(size);
    int temp = 0;
    for (size_t i = size; i > 0; --i)
    {
        sum.at(i - 1) = v1.at(i - 1) + v2.at(i - 1) + temp;
        temp = 0;
        if (sum.at(i - 1) > 9 and i != 1 and i!=0)
        {
            temp = sum.at(i - 1) / 10;
            sum.at(i - 1) %= 10;
        }
        if(i == 1){
            if (sum.at(0) > 9)
            {
                int carry = sum.at(0) / 10;
                sum.insert(sum.begin(), carry);
                sum.at(0) %= 10;
                sum.erase(sum.begin());
            }
        }
    }
    return sum;
}

int main()
{
    vector<int> v1 = {0};
    vector<int> v2 = {1};
    int number;
    cout << "Give me a number and I'll tell you the nth number of the Fibonacci sequence: ";
    cin >> number;
    if(number == 0 or number == 1){
        cout << "0 is the first element in the sequence" << endl;
    }else if(number == 2 or number == 3){
        cout << "1 is the second and third element in the sequence" << endl;
    }else{
        // Loop to get nth number of the Fibonacci sequence
        for (int i = 1; i < number; ++i)
        {   
            vector<int> temp = add(v1, v2);
            v2 = v1;
            v1 = temp;
        }
        // cout the number
        for(size_t i = 0; i < v1.size(); ++i){
            cout << v1.at(i);
        }
    }
}