#include "Rationnel.hpp"
#include <iostream>

Rationnel::Rationnel() {}
Rationnel::Rationnel(const std::string &s)
{
    std::string temp = s;
    if (s.front() == '-')
    {
        negative = true;
        temp = temp.substr(1);
    }
    else
        negative = false;

    bool found_separator = false;
    for (auto i = temp.crbegin(); i != temp.crend(); ++i)
    {
        if (found_separator == true)
        {
            numerator.value.push_back(*i - 48U);
        }
        else
        {
            if (*i == '/' || *i == ',' || *i == '.')
            {
                found_separator = true;
            }
            else
            {
                denominator.value.push_back(*i - 48U);
            }
        }
    }
    if (numerator.getSize() == 0)
    {
        numerator = denominator;
        denominator = 1;
    }
    else
    {
        simplify();
    }
}

Rationnel::Rationnel(const int &number)
{
    negative = !(number > 0);
    numerator = number;
    denominator = 1;
}

void Rationnel::simplify()
{
    Uint gcd = get_gcd(numerator, denominator);
    if (gcd != 0)
    {
        numerator /= gcd;
        denominator /= gcd;
    }
}

std::ostream &operator<<(std::ostream &out, const Rationnel &r)
{
    if (r.negative)
    {
        out << "-";
    }

    if (r.denominator != 1)
    {
        out << r.numerator << "/" << r.denominator;
    }
    else
    {
        out << r.numerator;
    }
    return out;
}

std::istream &operator>>(std::istream &is, Rationnel &r){
    std::string buffer;
    if (is >> buffer)
        r = buffer;
    else
        is.clear(std::ios::badbit | is.rdstate());
    return is;
}

Rationnel operator*(double left, const Rationnel &right)
{
    return right * left;
}

Rationnel Rationnel::operator+(const Rationnel &right) const
{
    Rationnel temp = *this;
    temp += right;
    return temp;
}

Rationnel Rationnel::operator-(const Rationnel &right) const
{
    Rationnel temp = *this;
    temp -= right;
    return temp;
}

Rationnel Rationnel::operator*(const Rationnel &right) const
{
    Rationnel temp = *this;
    temp *= right;
    return temp;
}

Rationnel Rationnel::operator*(double right) const
{
    Rationnel temp = *this;
    Rationnel new_right = int(right);
    temp *= new_right;
    return temp;
}

Rationnel Rationnel::operator/(const Rationnel &right) const
{
    Rationnel temp = *this;
    temp /= right;
    return temp;
}

Rationnel Rationnel::operator/(double right) const
{
    Rationnel temp = *this;
    Rationnel new_right = int(right);
    temp /= new_right;
    return temp;
}

Rationnel Rationnel::operator++(int)
{
    Rationnel tmp = *this;
    ++(*this);
    return tmp;
}

Rationnel &Rationnel::operator++()
{
    *this += Rationnel(1);
    return *this;
}

Rationnel Rationnel::operator--(int)
{
    Rationnel tmp = *this;
    --(*this);
    return tmp;
}

Rationnel &Rationnel::operator--()
{
    *this -= 1;
    return *this;
}

Rationnel &Rationnel::operator+=(const Rationnel &right)
{
    Rationnel temp = right;
    temp.numerator *= denominator;
    denominator *= temp.denominator;
    numerator *= temp.denominator;
    if (negative == true && right.negative == false)
    {
        numerator = numerator - temp.numerator;
        negative = true;
    }
    else if (negative == false && right.negative == true)
    {
        numerator = temp.numerator - numerator;
        negative = true;
    }
    else if (negative == true && right.negative == negative)
    {
        numerator += temp.numerator;
        negative = false;
    }
    else
    {
        numerator += temp.numerator;
        negative = false;
    }
    simplify();
    return *this;
}

Rationnel &Rationnel::operator-=(const Rationnel &right)
{
    Rationnel temp = right;
    temp.numerator *= denominator;
    denominator *= temp.denominator;
    numerator *= temp.denominator;
    if (negative == true && right.negative == false)
    {
        numerator += temp.numerator;
        negative = true;
    }
    else if (negative == false && right.negative == true)
    {
        numerator += temp.numerator;
        negative = false;
    }
    else if (negative == true && right.negative == negative)
    {
        numerator += temp.numerator;
        negative = true;
    }
    else
    {
        numerator = temp.numerator - numerator;
        negative = true;
    }
    simplify();
    return *this;
}

Rationnel &Rationnel::operator*=(const Rationnel &right)
{
    negative = !(negative == right.negative);
    numerator *= right.numerator;
    denominator *= right.denominator;
    simplify();
    return *this;
}

Rationnel &Rationnel::operator*=(double right)
{
    Rationnel temp = *this;
    Rationnel new_right = int(right);
    temp *= new_right;
    return temp;
}

Rationnel &Rationnel::operator/=(const Rationnel &right)
{
    negative = !(negative == right.negative);
    numerator *= right.denominator;
    denominator *= right.numerator;
    simplify();
    return *this;
}

Rationnel &Rationnel::operator/=(double right)
{
    Rationnel temp = *this;
    Rationnel new_right = int(right);
    temp /= new_right;
    simplify();
    return temp;
}

Rationnel &Rationnel::operator-()
{
    if (numerator == 0)
    {
        negative = false;
    }
    else
    {
        negative = !negative;
    }
    return *this;
}

/**
 * @brief Used for boolean comparison operator overloads
 *
 * @param left left hand side of comparison
 * @param right right hand side of comparison
 * @return int -1 if left < right, 0 if equal else 1
 */
int Rationnel::compRat(const Rationnel &left, const Rationnel &right) const
{
    Uint new_left = left.numerator * right.denominator;
    Uint new_right = right.numerator * right.denominator;
    if (left.negative == true && right.negative != left.negative)
    {
        return -1;
    }
    else if (left.negative == false && right.negative != left.negative)
    {
        return 1;
    }
    else if (left.negative == true && right.negative == left.negative)
    {
        if (new_left > new_right)
        {
            return 1;
        }
        else if (new_left < new_right)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

bool Rationnel::operator<(const Rationnel &right) const { return compRat(*this, right) == -1; }
bool Rationnel::operator<=(const Rationnel &right) const { return compRat(*this, right) != 1; }
bool Rationnel::operator>(const Rationnel &right) const { return compRat(*this, right) == 1; }
bool Rationnel::operator>=(const Rationnel &right) const { return compRat(*this, right) != -1; }
bool Rationnel::operator==(const Rationnel &right) const { return compRat(*this, right) == 0; }
bool Rationnel::operator!=(const Rationnel &right) const { return compRat(*this, right) != 0; }