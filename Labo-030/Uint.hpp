#ifndef UINT_HPP
#define UINT_HPP

#include <vector>
#include <string>

const uint32_t ASCII_ZERO = 48; // ASCII Value of 0

class  Uint{
    std::vector<uint32_t> value = {};
    Uint &carry();
    int compare(const Uint &left, const Uint &right) const;
    void fixValue();
    Uint division(const Uint &dividend, const Uint &divisor, Uint &remainder);

    public:
    // Constructors
    Uint();
    Uint(const std::string &number);
    Uint(uint64_t unsigned_number);
    // Friends
    friend std::ostream &operator<<(std::ostream &left, const Uint &right);
    friend Uint operator*(uint32_t left, const Uint &right);

    // Arithmetic operator overloads
    Uint operator+(const Uint &right) const;
    Uint operator-(const Uint &right) const;
    Uint operator*(const Uint &right) const;
    Uint operator*(uint32_t &right) const;
    Uint operator/(const Uint &right) const;
    Uint operator/(uint32_t &right) const;
    Uint operator%(const Uint &right) const;
    Uint operator%(uint32_t &right) const;
    Uint &operator++();
    Uint &operator++(int dummy);
    Uint &operator--();
    Uint &operator--(int dummy);
    Uint &operator+=(const Uint &right);
    Uint &operator-=(const Uint &right);
    Uint &operator*=(const Uint &right);
    Uint &operator*=(uint32_t &right);
    Uint &operator/=(const Uint &right);
    Uint &operator/=(uint32_t &right);
    Uint &operator%=(const Uint &right);
    Uint &operator%=(uint32_t &right);
    
    // Comparison operator overloads
    bool operator<(const Uint &right) const;
    bool operator<=(const Uint &right) const;
    bool operator>(const Uint &right) const;
    bool operator>=(const Uint &right) const;
    bool operator==(const Uint &right) const;
    bool operator!=(const Uint &right) const;
};
#endif