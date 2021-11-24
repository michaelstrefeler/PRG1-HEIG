/**
 * @file strefeler_labo23.cpp
 * @author Michael Strefeler
 * @brief Use vectors to multiply arbitarily long numbers, an element is a digit
 * @version 0.1
 * @date 23-11-2021
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void showVectorValues(const vector<int> v);
vector<int> add(vector<int> v1, vector<int> v2);
vector<int> mutliply(vector<int> v1, vector<int> v2);

int main()
{
    vector<int> v1 = {7, 5, 6, 4};
    vector<int> v2 = {3, 6, 9};
    mutliply(v1, v2);
}

/**
 * @brief multiply arbitrarily long numbers
 *
 * @param v1 digits of first number
 * @param v2 digits of second number
 * @return vector<int> product of the two numbers
 */
vector<int> mutliply(vector<int> v1, vector<int> v2)
{
    // 68076
    reverse(v2.begin(), v2.end());
    for(size_t i = 0; i < v1.size(); ++i){
        for(size_t j = 0; j < v2.size(); ++j){
            
        }
    }
    return {1};
}

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
        if (sum.at(i - 1) > 9 and i != 1 and i != 0)
        {
            temp = sum.at(i - 1) / 10;
            sum.at(i - 1) %= 10;
        }
        if (i == 1)
        {
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

void showVectorValues(vector<int> v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << v.at(i);
    }
    cout << endl;
}
