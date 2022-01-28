#include "Rationnel.hpp"
#include <algorithm>
#include <iostream>

Rationnel::Rationnel() {
    numerator = 0;
    denominator = 1;
    negative = false;
}

Rationnel::Rationnel(const std::string &s)
{
    std::string temp = s;
    std::string separator = "/";
    size_t pos = s.find_first_of(separator);
    std::string top = s.substr(0, pos); // numerator
    std::string bottom = s.substr(pos + 1); // denominator

    // Reverse string so push_back puts the digits in the correct order
    reverse(top.begin(), top.end());
    reverse(bottom.begin(), bottom.end());

    negative = false;
    if (top.length() == 0)
    {
        throw std::invalid_argument("Not a valid number");
    }
    for (size_t i = 0; i < top.length(); ++i)
    {
        if (isdigit(top.at(i)))
        {
            numerator.value.push_back(top.at(i) - 48U); // ASCII value - ASCII of zero
        }
        if(top.at(i) == '-'){
            negative = !negative;
        }
    }
    if (bottom.length() == 0 || bottom == top)
    {
        if(numerator == 0)
            throw std::invalid_argument("Not a valid number");
        if (denominator == 0)
            throw std::invalid_argument("Not a valid number");
        else
            denominator = 1;
    }
    else
    {
        for (size_t i = 0; i < bottom.length(); ++i)
        {
            if (isdigit(bottom.at(i)))
            {
                denominator.value.push_back(bottom.at(i) - 48U); // ASCII value - ASCII of zero
            }
            if (bottom.at(i) == '-')
            {
                negative = !negative;
            }
        }
    }
    if (denominator == 0)
        throw std::invalid_argument("Not a valid number");
    if (numerator == 0 && negative == true)
        throw std::invalid_argument("Not a valid number");

    if (numerator == 0 && denominator == 0)
        throw std::invalid_argument("Not a valid number");
    
    simplify();
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

std::istream &operator>>(std::istream &is, Rationnel &r)
{
    std::string buffer;
    if (is >> buffer){
        Rationnel temp(buffer);
        r = temp;
    }
    else{
        is.clear(std::ios::badbit | is.rdstate());
    }
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
    *this += 1;
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
    numerator *= temp.denominator;
    temp.numerator *= denominator;
    denominator *= temp.denominator;
    if (negative == true && right.negative == false)
    {
        if (numerator > temp.numerator)
        {
            numerator = numerator - temp.numerator;
            negative = true;
        }
        else if (numerator < temp.numerator)
        {
            numerator = temp.numerator - numerator;
            negative = false;
        }
        else
        {
            numerator = 0;
            negative = false;
        }
    }
    else if (negative == false && right.negative == true)
    {
        if(numerator > temp.numerator){
            numerator = numerator - temp.numerator;
            negative = false;
        }
        else if (numerator < temp.numerator)
        {
            numerator = temp.numerator - numerator;
            negative = true;
        }else{
            numerator = 0;
            negative = false;
        }
        
    }
    else if (negative == true && right.negative == true)
    {
        numerator = numerator + temp.numerator;
        negative = true;
    }
    else
    {
        numerator = numerator + temp.numerator;
        negative = false;
    }
    simplify();
    return *this;
}

Rationnel &Rationnel::operator-=(const Rationnel &right)
{
    Rationnel temp = right;
    numerator *= temp.denominator;
    temp.numerator *= denominator;
    denominator *= temp.denominator;
    if (negative == true && right.negative == false)
    {
        if (numerator > temp.numerator)
        {
            numerator = numerator + temp.numerator;
            negative = true;
        }
        else if (numerator < temp.numerator)
        {
            numerator = numerator + temp.numerator;
            negative = true;
        }
        else
        {
            numerator = numerator + temp.numerator;
            negative = true;
        }
    }
    else if (negative == false && right.negative == true)
    {
        numerator += temp.numerator;
        negative = false;
    }
    else if (negative == true && right.negative == true)
    {
        if (numerator > temp.numerator)
        {
            numerator = numerator - temp.numerator;
            negative = true;
        }
        else if (numerator < temp.numerator)
        {
            numerator = temp.numerator - numerator;
            negative = false;
        }
        else
        {
            numerator = 0;
            negative = false;
        }
    }
    else
    {
        if(numerator > temp.numerator){
            numerator = numerator - temp.numerator;
            negative = false;
        }
        else if (numerator < temp.numerator)
        {
            numerator = temp.numerator - numerator;
            negative = true;
        }else{
            numerator = 0;
            negative = false;
        }
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
    simplify();
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
    Uint new_right = right.numerator * left.denominator;
    if (left.negative == true && right.negative == false)
    {
        return -1;
    }
    else if (left.negative == false && right.negative == true)
    {
        return 1;
    }
    else if (left.negative == true && right.negative == true)
    {
        if (new_left > new_right)
        {
            return -1;
        }
        else if (new_left < new_right)
        {
            return 1;
        }else{
            return 0;
        }
    }else{
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
    return 1;
}

bool Rationnel::operator<(const Rationnel &right) const { return compRat(*this, right) == -1; }
bool Rationnel::operator<=(const Rationnel &right) const { return compRat(*this, right) != 1; }
bool Rationnel::operator>(const Rationnel &right) const { return compRat(*this, right) == 1; }
bool Rationnel::operator>=(const Rationnel &right) const { return compRat(*this, right) != -1; }
bool Rationnel::operator==(const Rationnel &right) const { return compRat(*this, right) == 0; }
bool Rationnel::operator!=(const Rationnel &right) const { return compRat(*this, right) != 0; }