#ifndef UINT_HPP
#define UINT_HPP

#include <vector>
#include <string>

const uint32_t ASCII_ZERO = 48;

class Uint
{
private:
    std::vector<uint32_t> value;
    Uint &carry();
    int compare(const Uint &left, const Uint &right) const;
    void fixValue();
    Uint division(const Uint &dividend, const Uint &divisor, Uint &remainder);

public:
    Uint();
    Uint(const std::string &s);
    Uint(uint64_t u);
    bool isEven() const;

    friend Uint mod_pow(Uint base, Uint exp, const Uint &mod);
    friend class Sint;
    friend Uint operator*(uint32_t left, const Uint &right);
    friend std::ostream &operator<<(std::ostream &out, const Uint &u);
    friend std::istream &operator>>(std::istream &is, Uint &u);

    Uint operator+(const Uint &right) const;
    Uint operator-(const Uint &right) const;
    Uint operator*(const Uint &right) const;
    Uint operator*(uint32_t right) const;
    Uint operator/(const Uint &right) const;
    Uint operator/(uint32_t right) const;
    Uint operator%(const Uint &right) const;
    Uint operator%(uint32_t right) const;
    Uint operator++(int);
    Uint &operator++();
    Uint operator--(int);
    Uint &operator--();
    Uint &operator+=(const Uint &right);
    Uint &operator-=(const Uint &right);
    Uint &operator*=(const Uint &right);
    Uint &operator*=(uint32_t right);
    Uint &operator/=(const Uint &right);
    Uint &operator/=(uint32_t right);
    Uint &operator%=(const Uint &right);
    Uint &operator%=(uint32_t right);

    bool operator<(const Uint &right) const;
    bool operator<=(const Uint &right) const;
    bool operator>(const Uint &right) const;
    bool operator>=(const Uint &right) const;
    bool operator==(const Uint &right) const;
    bool operator!=(const Uint &right) const;
    explicit operator uint64_t() const;
};

#endif