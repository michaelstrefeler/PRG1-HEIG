#ifndef SINT_HPP
#define SINT_HPP
#include "Uint.hpp"

class Sint{
private:
    Uint value;
    bool negative;
    int compare(const Sint &left, const Sint &right) const;

public:
    Sint();
    Sint(const std::string &s);
    Sint(int64_t number);
    bool isEven() const;

    friend Sint mod_pow(Sint base, Sint exp, const Sint &mod);
    friend Sint operator*(int32_t left, const Sint &right);
    friend std::ostream &operator<<(std::ostream &out, const Sint &u);
    friend std::istream &operator>>(std::istream &is, Sint &u);

    Sint operator+(const Sint &right) const;
    Sint operator-(const Sint &right) const;
    Sint operator*(const Sint &right) const;
    Sint operator*(int32_t right) const;
    Sint operator/(const Sint &right) const;
    Sint operator/(int32_t right) const;
    Sint operator%(const Sint &right) const;
    Sint operator%(int32_t right) const;
    Sint operator++(int);
    Sint &operator++();
    Sint operator--(int);
    Sint &operator--();
    Sint &operator+=(const Sint &right);
    Sint &operator-=(const Sint &right);
    Sint &operator*=(const Sint &right);
    Sint &operator*=(int32_t right);
    Sint &operator/=(const Sint &right);
    Sint &operator/=(int32_t right);
    Sint &operator%=(const Sint &right);
    Sint &operator%=(int32_t right);

    bool operator<(const Sint &right) const;
    bool operator<=(const Sint &right) const;
    bool operator>(const Sint &right) const;
    bool operator>=(const Sint &right) const;
    bool operator==(const Sint &right) const;
    bool operator!=(const Sint &right) const;
    explicit operator int64_t() const;
    Sint &operator-();
};
#endif