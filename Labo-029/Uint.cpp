/**
 * @file Uint.cpp
 * @author Michael Strefeler
 * @brief
 * @version 0.1
 * @date 14-12-2021
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

const uint32_t ZERO_ASCII = 48;

class Uint
{
    vector<uint32_t> value = {};
    friend Uint operator+(Uint left, const Uint &right);
    friend ostream &operator<<(ostream &lhs, const Uint &rhs);

public:
    Uint() : value(){};
    Uint(string val);
    Uint(uint32_t val);
    Uint &operator+=(const Uint &right);
    void carry();
};

Uint::Uint(string val)
{
    for (auto i = val.begin(); i != val.end(); ++i)
    {
        if (isdigit(*i))
        {
            value.push_back(*i - ZERO_ASCII);
        }
    }
}

Uint::Uint(uint32_t val)
{
    *this = to_string(val);
}

void Uint::carry()
{
    for (size_t i = 0; i < value.size(); i++)
    {
        if (value.at(i) > 0)
        {
            if (i != value.size() - 1)
            {
                value.at(i + 1) += value.at(i) / 10;
                value.at(i) %= 10;
            }
            else
            {
                value.push_back(value.at(1) / 10);
                value.at(i) %= 10;
            }
        }
    }
}

Uint operator+(Uint left, const Uint &right)
{
    left += right;
    return left;
}

Uint &Uint::operator+=(const Uint &right)
{
    for (size_t i = value.size(); i < right.value.size(); --i)
    {
        this->value.push_back(0);
    }
    for (size_t i = 0; i < value.size(); i++)
    {
        value.at(i) += right.value.at(i);
        this->carry();
    }
    return *this;
}

ostream &operator<<(ostream &lhs, const Uint &rhs)
{
    for (auto i = rhs.value.begin(); i != rhs.value.end(); ++i)
    {
        lhs << *i;
    }
    return lhs;
}

int main()
{
    string number;
    cout << "Give me an unsigned number: ";
    getline(cin, number);
    // size_t nb = stoul(number);

    Uint n;           // Empty constructor
    n = Uint(number); // String constructor
    cout << "Number read " << n << endl;
}