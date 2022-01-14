#include "Uint.hpp"
#include <iostream>
#include <sstream>

Uint::Uint() {}

Uint::Uint(const std::string &s)
{
    for (auto i = s.crbegin(); i != s.crend(); ++i)
    {
        if (isdigit(*i))
            value.push_back(uint32_t(*i) - ASCII_ZERO);
        else
            throw std::invalid_argument(
                "Not a valid number!");
    }
    fixValue();
}

bool Uint::isEven() const { return (value.front() % 2) == 0; }

Uint::Uint(uint64_t c) { *this = std::to_string(c); }

Uint &Uint::carry()
{
    for (size_t i = 0; i < value.size(); ++i)
    {
        if (i == value.size() - 1)
        {
            if (value.at(i) >= 10)
                value.push_back(value.at(i) / 10);
        }
        else
            value.at(i + 1) += value.at(i) / 10;

        value.at(i) %= 10;
    }

    return *this;
}

int Uint::compare(const Uint &left, const Uint &right) const
{
    if (left.value.size() == right.value.size())
    {
        for (auto l = left.value.crbegin(), r = right.value.crbegin();
             l != left.value.crend(); ++l, ++r)
        {
            if (*l < *r)
                return -1;
            else if (*l > *r)
                return 1;
        }
        return 0;
    }
    else if (left.value.size() < right.value.size())
        return -1;
    return 1;
}

void Uint::fixValue()
{
    while (value.size() > 1 && *(value.end() - 1) == 0)
        value.erase((value.end() - 1));
}

Uint Uint::division(const Uint &dividend, const Uint &divisor, Uint &remainder)
{
    Uint temp(1), divisorTemp = divisor, quotient(0);

    while (divisorTemp <= dividend)
    {
        temp *= 2;
        divisorTemp *= 2;
    }

    remainder = dividend;

    while (remainder >= divisor)
    {
        divisorTemp /= 2;
        temp /= 2;

        if (remainder >= divisorTemp)
        {
            quotient += temp;
            remainder -= divisorTemp;
        }
    }
    return quotient;
}

size_t Uint::getSize() const { return value.size(); }

Uint mod_pow(Uint base, Uint exp, const Uint &mod)
{
    Uint result = 1;

    while (exp > 0)
    {
        if (exp.isEven())
        {
            base = base * base % mod;
            exp /= 2;
        }
        else
        {
            result = result * base % mod;
            --exp;
        }
    }
    return result;
}

Uint operator*(uint32_t left, const Uint &right) { return right * left; }

std::ostream &operator<<(std::ostream &out, const Uint &u)
{
    for (auto i = u.value.crbegin(); i != u.value.crend(); ++i)
        out << *i;

    return out;
}

std::istream &operator>>(std::istream &is, Uint &u)
{
    std::string buffer;
    if (is >> buffer)
        u = buffer;
    else
        is.clear(std::ios::badbit | is.rdstate());

    return is;
}

Uint Uint::operator+(const Uint &right) const
{
    Uint temp = *this;
    temp += right;
    return temp;
}

Uint Uint::operator-(const Uint &right) const
{
    Uint temp = *this;
    temp -= right;
    return temp;
}

Uint Uint::operator*(const Uint &right) const
{
    Uint temp = *this;
    temp *= right;
    return temp;
}

Uint Uint::operator*(uint32_t right) const
{
    Uint temp = *this;
    temp *= right;
    return temp;
}

Uint Uint::operator/(const Uint &right) const
{
    Uint temp = *this;
    temp /= right;
    return temp;
}

Uint Uint::operator/(uint32_t right) const
{
    Uint temp = *this;
    temp /= right;
    return temp;
}

Uint Uint::operator%(const Uint &right) const
{
    Uint temp = *this;
    temp %= right;
    return temp;
}

Uint Uint::operator%(uint32_t right) const
{
    Uint temp = *this;
    temp %= right;
    return temp;
}

Uint Uint::operator++(int)
{
    Uint tmp = *this;
    ++(*this);
    return tmp;
}

Uint &Uint::operator++()
{
    ++value.front();
    if (value.front() > 9)
        carry();
    return *this;
}

Uint Uint::operator--(int)
{
    Uint tmp = *this;
    --(*this);
    return tmp;
}

Uint &Uint::operator--()
{
    if (value.front() > 1)
        --value.front();
    else
    {
        *this -= 1;
        return carry();
    }
    return *this;
}

Uint &Uint::operator+=(const Uint &right)
{
    if (value.size() < right.value.size())
        value.resize(uint32_t(right.value.size()), 0);

    for (size_t i = 0; i < right.value.size(); ++i)
        value.at(i) += right.value.at(i);
    return carry();
}

Uint &Uint::operator-=(const Uint &right)
{
    Uint temp = right;
    if (*this < right)
        throw std::invalid_argument("Negative difference not permitted");

    if (value.size() > temp.value.size())
        temp.value.resize(uint32_t(value.size()), 0);

    for (size_t i = 0; i < value.size(); ++i)
    {
        if (value.at(i) < temp.value.at(i))
        {
            temp.value.at(i + 1)++;
            value.at(i) += 10;
        }
        value.at(i) -= temp.value.at(i);
    }
    fixValue();

    return *this;
}

Uint &Uint::operator*=(const Uint &right)
{
    Uint temp = 0;
    for (size_t i = 0; i != right.value.size(); i++)
    {
        temp += right.value.at(i) * *this;

        if (i != right.value.size() - 1)
            value.insert(value.cbegin(), 0);
    }

    *this = temp;

    return *this;
}

Uint &Uint::operator*=(uint32_t right)
{
    for (uint32_t i = 0; i < value.size(); ++i)
        value.at(i) *= right;
    return carry();
}

Uint &Uint::operator/=(const Uint &right)
{
    if (right == Uint(0))
        throw std::runtime_error("Zero division error!");

    Uint remainder;
    *this = division(*this, right, remainder);
    return *this;
}

Uint &Uint::operator/=(uint32_t right)
{
    if (right == 0)
        throw std::runtime_error("Zero division error!");

    for (size_t i = value.size() - 1; i > 0; i--)
    {
        value.at(i - 1) += (value.at(i) % right) * 10;
        value.at(i) /= right;
    }
    value.at(0) /= right;
    fixValue();

    return *this;
}

Uint &Uint::operator%=(const Uint &right)
{
    division(*this, right, *this);
    return *this;
}

Uint &Uint::operator%=(uint32_t right)
{
    return *this -= (*this / right) * right;
}

bool Uint::operator<(const Uint &right) const { return compare(*this, right) == -1; }

bool Uint::operator<=(const Uint &right) const { return compare(*this, right) != 1; }

bool Uint::operator>(const Uint &right) const { return compare(*this, right) == 1; }

bool Uint::operator>=(const Uint &right) const { return compare(*this, right) != -1; }

bool Uint::operator==(const Uint &right) const { return compare(*this, right) == 0; }

bool Uint::operator!=(const Uint &right) const { return compare(*this, right) != 0; }

Uint::operator uint64_t() const
{
    try
    {
        std::stringstream convert;
        convert << *this;
        return std::stoull(convert.str());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << ": Number greater than uint64_t max value" << '\n';
        return 0;
    }
}