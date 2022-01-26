#ifndef RATIONNEL_HPP
#define RATIONNEL_HPP
#include "Uint.hpp"

class Rationnel{
private:
    Uint numerator;
    Uint denominator;
    bool negative;

    /**
     * @brief Used for boolean comparison operator overloads
     *
     * @param left left hand side of comparison
     * @param right right hand side of comparison
     * @return int -1 if left < right, 0 if equal else 1
     */
    int compRat(const Rationnel &left, const Rationnel &right) const;
    void simplify();
public:
    Rationnel();
    Rationnel(const std::string &s);
    Rationnel(const int &number);
    friend Rationnel operator*(double left, const Rationnel &right);
    friend std::ostream &operator<<(std::ostream &out, const Rationnel &s);
    friend std::istream &operator>>(std::istream &is, Rationnel &s);

    // Artithmetic operator overloads
    Rationnel operator+(const Rationnel &right) const;
    Rationnel operator-(const Rationnel &right) const;
    Rationnel operator*(const Rationnel &right) const;
    Rationnel operator*(double right) const;
    Rationnel operator/(const Rationnel &right) const;
    Rationnel operator/(double right) const;
    Rationnel operator++(int);
    Rationnel &operator++();
    Rationnel operator--(int);
    Rationnel &operator--();
    Rationnel &operator+=(const Rationnel &right);
    Rationnel &operator-=(const Rationnel &right);
    Rationnel &operator*=(const Rationnel &right);
    Rationnel &operator*=(double right);
    Rationnel &operator/=(const Rationnel &right);
    Rationnel &operator/=(double right);
    Rationnel &operator-();

    // Boolean comparison operator overloads
    bool operator<(const Rationnel &right) const;
    bool operator<=(const Rationnel &right) const;
    bool operator>(const Rationnel &right) const;
    bool operator>=(const Rationnel &right) const;
    bool operator==(const Rationnel &right) const;
    bool operator!=(const Rationnel &right) const;
};
#endif