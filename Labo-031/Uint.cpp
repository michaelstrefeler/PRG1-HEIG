#include "Uint.hpp";
#include <iostream>;

Uint::Uint() {}

Uint::Uint(const std::string &number)
{
    for (auto it = number.crbegin(); it != number.crend(); ++it)
    {
        if (isdigit(*it))
            value.push_back(uint32_t(*it) - ASCII_ZERO);
        else
            throw std::invalid_argument("Not a number");
    }
    fixValue();
}

Uint::Uint(uint64_t unsigned_number) { *this = std::to_string(unsigned_number); }

Uint &Uint::carry()
{
    for (size_t size = 0; size < value.size(); ++size)
    {
        if (size == value.size() - 1)
        {
            if (value.at(size) >= 10)
            {
                value.push_back(value.at(size) / 10);
            }
        }
        else
        {
            value.at(size + 1) += value.at(size) / 10;
        }
    }
    return *this;
}

int Uint::compare(const Uint &left, const Uint &right) const
{
    if (left.value.size() == right.value.size())
    {
        for (auto l = left.value.crbegin(), r = right.value.crbegin(); l != left.value.crend(); ++l, ++r)
        {
            if (*l < *r)
            {
                return -1;
            }
            else if (*l > *r)
            {
                return 1;
            }
        }
        return 0;
    }
    else if (left.value.size() < right.value.size())
    {
        return -1;
    }
    return 1;
}

void Uint::fixValue()
{
    while (value.size() > 1 and *(value.end() - 1) == 0)
    {
        value.erase((value.end() - 1));
    }
}

Uint Uint::division(const Uint &dividend, const Uint &divisor, Uint &remainder)
{
    Uint temp(1);
    Uint temp_divisor = divisor;
    Uint quotient(0);

    while (temp_divisor <= divisor)
    {
        temp *= 2;
        temp_divisor *= 2;
    }

    remainder = dividend;

    while (remainder >= divisor)
    {
        quotient += temp;
        remainder -= temp_divisor;
    }
    return quotient;
}

std::ostream &operator<<(std::ostream &left, const Uint &right)
{
    for (auto r = right.value.crbegin(); r != right.value.crend(); ++r)
    {
        left << *r;
    }
    return left;
}

Uint operator*(uint32_t left, const Uint &right) { return left * right; }

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

Uint Uint::operator*(uint32_t &right) const
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

Uint Uint::operator/(uint32_t &right) const
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

Uint Uint::operator%(uint32_t &right) const
{
    Uint temp = *this;
    temp %= right;
    return temp;
}

Uint &Uint::operator++(int dummy)
{
    Uint temp = *this;
    ++(*this);
    return temp;
}

Uint &Uint::operator++()
{
    ++value.front();
    if (value.front() > 9)
    {
        carry();
    }
    return *this;
}

Uint &Uint::operator--(int dummy)
{
    Uint temp = *this;
    --(*this);
    return temp;
}

Uint &Uint::operator--()
{
    if (value.front() > 1)
    {
        --value.front();
    }
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
    {
        value.resize(uint32_t(right.value.size()), 0);
    }

    for (size_t i = 0; i < right.value.size(); ++i)
    {
        value.at(i) += right.value.at(i);
    }

    return carry();
}

Uint &Uint::operator-=(const Uint &right)
{
    Uint temp = right;
    if (*this < right)
    {
        throw std::invalid_argument("Negative difference not allowed!");
    }

    if (value.size() > right.value.size())
    {
        temp.value.resize(uint32_t(value.size()), 0);
    }

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
        temp += right.value.at(i) * (*this);

        if (i != right.value.size() - 1)
        {
            value.insert(value.cbegin(), 0);
        }
    }

    *this = temp;
    return *this;
}

Uint &Uint::operator*=(uint32_t &right)
{
    for (uint32_t i = 0; i < value.size(); ++i)
    {
        value.at(i) *= right;
    }

    return carry();
}

Uint &Uint::operator/=(const Uint &right)
{
    if (right == Uint(0))
    {
        throw std::runtime_error("Zero division error");
    }

    Uint remainder;
    *this = division(*this, right, remainder);
    return *this;
}

Uint &Uint::operator/=(uint32_t &right)
{
    if (right == 0)
    {
        throw std::runtime_error("Zero division error");
    }

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

Uint &Uint::operator%=(uint32_t &right)
{
    return *this -= (*this / right) * right;
}

bool Uint::operator<(const Uint &right) const { return compare(*this, right) == -1; };
bool Uint::operator<=(const Uint &right) const { return compare(*this, right) != 1; };
bool Uint::operator>(const Uint &right) const { return compare(*this, right) == 1; };
bool Uint::operator>=(const Uint &right) const { return compare(*this, right) != -1; };
bool Uint::operator==(const Uint &right) const { return compare(*this, right) == 0; };
bool Uint::operator!=(const Uint &right) const { return compare(*this, right) != 0; };