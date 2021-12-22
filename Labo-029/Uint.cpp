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
#include <algorithm>
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
    friend Uint operator-(Uint left, const Uint &right);
    friend ostream &operator<<(ostream &left, const Uint &right);
    int compare(const Uint &left, const Uint &right) const;

public:
    Uint() : value(){}; // Default constructor
    Uint(string val);   // String constructor
    Uint(uint32_t val); // uint32_t constructor
    Uint &operator+=(const Uint &right);
    Uint &operator-=(const Uint &right);
    void carry();
    // Comparison operator overloading
    bool operator<(const Uint &right) const;
    bool operator<=(const Uint &right) const;
    bool operator>(const Uint &right) const;
    bool operator>=(const Uint &right) const;
    bool operator==(const Uint &right) const;
    bool operator!=(const Uint &right) const;
};

Uint::Uint(string val)
{
    for (auto i = val.begin(); i != val.end(); ++i)
    {
        if (isdigit(*i))
        {
            value.push_back(uint32_t(*i) - ZERO_ASCII);
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

Uint operator-(Uint left, const Uint &right)
{
    left -= right;
    return left;
}

Uint &Uint::operator-=(const Uint &right)
{
    Uint temp = right;
    if (this->value.size() < temp.value.size())
    {
        cerr << "Error: Negative difference not allowed";
    }
    else
    {
        while (temp.value.size() < this->value.size())
        {
            temp.value.insert(temp.value.begin(), 0);
        }
        vector<uint32_t> difference = {};
        for (size_t i = this->value.size() - 1; i + 1 > 0; --i)
        {
            if ((int(this->value.at(i)) - int(temp.value.at(i))) > 0)
            {
                difference.push_back(this->value.at(i) - temp.value.at(i));
            }
            else
            {
                this->value.at(i - 1) -= 1;
                this->value.at(i) += 10;
                difference.push_back(this->value.at(i) - temp.value.at(i));
            }
        }
        reverse(difference.begin(), difference.end());
        this->value = difference;
    }
    return *this;
}

int Uint::compare(const Uint &left, const Uint &right) const
{
    if (left.value.size() == right.value.size())
    {
        for (auto lhs = left.value.cbegin(), rhs = right.value.cbegin(); lhs != left.value.cend(); ++lhs, ++rhs)
        {
            if (*lhs < *rhs)
                return -1;
            else if (*lhs > *rhs)
                return 1;
        }
        return 0;
    }
    else if (left.value.size() < right.value.size())
    {
        return -1;
    }
    return 1;
}

bool Uint::operator<(const Uint &right) const { return compare(*this, right) == -1; }
bool Uint::operator<=(const Uint &right) const { return compare(*this, right) != 1; }
bool Uint::operator>(const Uint &right) const { return compare(*this, right) == 1; }
bool Uint::operator>=(const Uint &right) const { return compare(*this, right) != -1; }
bool Uint::operator==(const Uint &right) const { return compare(*this, right) == 0; }
bool Uint::operator!=(const Uint &right) const { return compare(*this, right) != 0; }

ostream &operator<<(ostream &left, const Uint &right)
{
    for (auto i = right.value.begin(); i != right.value.end(); ++i)
    {
        left << *i;
    }
    return left;
}

int main()
{
    string number;
    cout << "Give me an unsigned number: ";
    getline(cin, number);
    Uint n;           // Empty constructor
    n = Uint(number); // String constructor
    cout << "Number read " << n << endl;
    Uint n1(654);
    Uint n2(63);
    n1 -= n2;
    cout << n1 << endl;
}