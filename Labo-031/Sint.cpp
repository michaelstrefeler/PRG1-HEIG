#include "Sint.hpp"
#include <iostream>

Sint::Sint() {}

Sint::Sint(const std::string &s)
{
    std::string temp = s;
    if (temp.at(0) == '-')
    {
        negative = true;
        temp = temp.substr(1);
    }
    else
        negative = false;
    value = temp;
}

Sint::Sint(int64_t number)
{
    if (number >= 0)
    {
        value = int64_t(number);
        negative = false;
    }
    else
    {
        value = int64_t(-number);
        negative = true;
    }
}

uint32_t Sint::getSize() const { return uint32_t(value.getSize()); }

Sint::Sint(Uint number)
{
    negative = false;
    value = number;
}

int Sint::compare(const Sint &left, const Sint &right) const
{
    if (left.negative == true and right.negative == false)
    {
        return -1;
    }
    else if (right.negative == true and left.negative == false)
    {
        return 1;
    }
    else if (left.getSize() == right.getSize())
    {
        if (left.value < right.value)
            return -1;
        else if (left.value > right.value)
            return 1;
    }
    return 1;
}


Sint &Sint::operator-()
{
    negative = not(negative);
    return *this;
}

bool Sint::isEven() const { return value.isEven(); }

Sint operator*(int32_t left, const Sint &right) { return right * left; }

std::ostream &operator<<(std::ostream &left, const Sint &right)
{
    if (right.negative)
        left << '-';
    left << right.value;
    return left;
}

std::istream &operator>>(std::istream &is, Sint &s)
{
    std::string buffer;
    if (is >> buffer)
    {
        if ((buffer.at(0) == '-'))
        {
            s.negative = true;
            buffer = buffer.substr(1);
        }
        else
            s.negative = false;
        s.value = buffer;
    }
    else
        is.clear(std::ios::badbit | is.rdstate());

    return is;
}

Sint Sint::operator+(const Sint &right) const
{
    Sint temp = *this;
    temp += right;
    return temp;
}

Sint Sint::operator-(const Sint &right) const
{
    Sint temp = *this;
    temp -= right;
    return temp;
}

Sint Sint::operator*(const Sint &right) const
{
    Sint temp = *this;
    temp *= right;
    return temp;
}

Sint Sint::operator*(int32_t right) const
{
    Sint temp = *this;
    temp *= right;
    return temp;
}

Sint Sint::operator/(const Sint &right) const
{
    Sint temp = *this;
    temp /= right;
    return temp;
}

Sint Sint::operator/(int32_t right) const
{
    Sint temp = *this;
    temp /= right;
    return temp;
}

Sint Sint::operator%(const Sint &right) const
{
    Sint temp = *this;
    temp %= right;
    return temp;
}

Sint Sint::operator%(int32_t right) const
{
    Sint temp = *this;
    temp %= right;
    return temp;
}

Sint Sint::operator++(int)
{
    Sint tmp = *this;
    ++(*this);
    return tmp;
}

Sint &Sint::operator++()
{
    if (not(negative) || value == 0)
        ++value;
    else
        --value;

    if (value == 0)
        negative = false;
    return *this;
}

Sint Sint::operator--(int)
{
    Sint tmp = *this;
    --(*this);
    return tmp;
}

Sint &Sint::operator--()
{
    if (value == 0 || negative)
    {
        ++value;
        negative = true;
    }
    else
    {
        --value;
    }
    return *this;
}

Sint &Sint::operator+=(const Sint &right)
{
    if (negative == false && (negative == right.negative))
    {
        value += right.value;
    }
    else if (value > right.value)
    {
        value -= right.value;
    }
    else
    {
        value = right.value - value;
        negative = not(negative);
    }
    if (value == 0)
        negative = false;
    return *this;
}

Sint &Sint::operator-=(const Sint &right)
{
    Sint temp = right;
    return *this += -temp;
}

Sint &Sint::operator*=(const Sint &right)
{
    value *= right.value;
    negative = (negative ^ right.negative); // xor to check sign
    return *this;
}

Sint &Sint::operator*=(int32_t right)
{
    value *= abs(right);
    bool sign = right < 0;
    negative = (negative ^ sign); // xor to check sign
    return *this;
}

Sint &Sint::operator/=(const Sint &right)
{
    value /= right.value;
    negative = (negative ^ right.negative); // xor to check sign
    return *this;
}

Sint &Sint::operator/=(int32_t right)
{
    value /= abs(right);
    bool sign = right < 0;
    negative = (negative ^ sign); // xor to check sign
    return *this;
}

Sint &Sint::operator%=(const Sint &right)
{
    return *this -= (*this / right) * right;
}

Sint &Sint::operator%=(int32_t right)
{
    return *this;
}

bool Sint::operator<(const Sint &right) const { return compare(*this, right) == -1; }

bool Sint::operator<=(const Sint &right) const { return compare(*this, right) != 1; }

bool Sint::operator>(const Sint &right) const { return compare(*this, right) == 1; }

bool Sint::operator>=(const Sint &right) const { return compare(*this, right) != -1; }

bool Sint::operator==(const Sint &right) const { return compare(*this, right) == 0; }

bool Sint::operator!=(const Sint &right) const { return compare(*this, right) != 0; }

Sint::operator int64_t() const
{
    uint64_t temp = uint64_t(value);
    if (negative)
        temp = -temp;
    return int64_t(temp);
}

Sint Sint::division(const Sint &dividend, const Sint &divisor, Sint &remainder)
{
    Sint temp(1), divisorTemp = divisor, quotient(0);

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

Sint mod_pow(Sint base, Sint exp, const Sint &mod)
{
    Sint result = 1;

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

Sint euclidAlgo(Sint a, Sint b, Sint &inverse)
{
    Sint gcd = a;
    Sint gcd_prime = b;
    inverse = 0;
    Sint inverse_prime = 1;
    while (abs(int64_t(gcd_prime)) != 0)
    {
        Sint integer_part = gcd / gcd_prime;
        Sint temp_gcd = gcd;
        Sint temp_inverse = inverse;
        gcd = gcd_prime;
        inverse = inverse_prime;
        gcd_prime = temp_gcd - integer_part * gcd_prime;
        inverse_prime = temp_inverse - integer_part * inverse_prime;
    }
    if (inverse < 0)
    {
        inverse = inverse + a;
    }
    return gcd;
}