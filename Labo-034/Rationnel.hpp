#ifndef RATIONNEL_HPP
#define RATIONNEL_HPP
#include "Uint.hpp"

/**
 * @brief Rational numbers class for fractions of arbitrary sizes
 * 
 */
class Rationnel{
private:
    Uint numerator;
    Uint denominator;
    bool negative; // if true the number is negative

    /**
     * @brief Used for boolean comparison operator overloads
     *
     * @param left left hand side of comparison
     * @param right right hand side of comparison
     * @return int -1 if left < right, 0 if equal else 1
     */
    int compRat(const Rationnel &left, const Rationnel &right) const;

    /**
     * @brief Simplifies a fraction using the Greatest Common Divisor (GCD)
     * 
     */
    void simplify();
public:
    /**
     * @brief Construct a new Rationnel object without a parameter
     * 
     */
    Rationnel();

    /**
     * @brief Construct a new Rationnel object
     * 
     * @param s string
     */
    Rationnel(const std::string &s);

    /**
     * @brief Construct a new Rationnel object
     * 
     * @param number int
     */
    Rationnel(const int &number);

    /**
     * @brief Friend operator for multiplication to fix issue
     *        where a double is on the left
     *
     * @param left double that we want use in multiplication
     * @param right fraction that we want use in multiplication
     * @return Rationnel fraction result
     */
    friend Rationnel operator*(double left, const Rationnel &right);

    /**
     * @brief Operator for seeing the value of a Rationnel using cout
     * 
     * @param out output stream
     * @param r the rational number
     * @return std::ostream& the output stream that will be shown on-screen
     */
    friend std::ostream &operator<<(std::ostream &out, const Rationnel &r);

    /**
     * @brief Operator for managing user input
     * 
     * @param is input stream
     * @param r the rational number
     * @return std::istream& input stream used to put value in variable
     */
    friend std::istream &operator>>(std::istream &is, Rationnel &r);

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