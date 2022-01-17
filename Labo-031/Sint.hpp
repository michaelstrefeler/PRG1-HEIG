#ifndef SINT_HPP
#define SINT_HPP
#include "Uint.hpp"

/**
 * @brief Signed ints of arbitrary size
 * 
 */
class Sint{
private:
    Uint value;
    bool negative;

    /**
     * @brief Used for boolean comparison operator overloads
     *
     * @param left left hand side of comparison
     * @param right right hand side of comparison
     * @return int -1 if left < right, 0 if equal else 1
     */
    int compare(const Sint &left, const Sint &right) const;

    /**
     * @brief Division for signed ints
     * 
     * @param dividend 
     * @param divisor 
     * @param remainder 
     * @return Sint quotient
     */
    Sint division(const Sint &dividend, const Sint &divisor, Sint &remainder);

public:
    /**
     * @brief Construct a new Sint object
     * 
     */
    Sint();

    /**
     * @brief Construct a new Sint object
     * 
     * @param s string value
     */
    Sint(const std::string &s);

    /**
     * @brief Construct a new Sint object
     * 
     * @param number int64_t value
     */
    Sint(int64_t number);

    /**
     * @brief Construct a new Sint object
     * 
     * @param number using a Uint
     */
    Sint(Uint number);

    /**
     * @brief Check if a Sint is even
     * 
     * @return true 
     * @return false 
     */
    bool isEven() const;

    /**
     * @brief Get the Size of a Sint
     * 
     * @return uint32_t size
     */
    uint32_t getSize() const;

    /**
     * @brief Extended Euclidean algorithm
     *
     * @param a first number
     * @param b second number
     * @param inverse of b mod a
     * @return Sint : the Greatest common divisor of a and b
     */
    friend Sint euclidAlgo(Sint a, Sint b, Sint &inverse);

    /**
     * @brief Modular exponentiation
     *
     * @param base the base that we want to use
     * @param exp exponent of the base
     * @param mod what we're divding the rest by
     * @return Sint base^exposant modulo mod
     */
    friend Sint mod_pow(Sint base, Sint exp, const Sint &mod);

    /**
     * @brief overload the multiplication operator
     *
     * @param left left hand side of multiplication
     * @param right right hand side of multiplication
     * @return Sint procuct
     */
    friend Sint operator*(int32_t left, const Sint &right);

    /**
     * @brief << operator overload to be able to show the value of a Uint
     *
     * @param out output stream
     * @param s Sint
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &out, const Sint &s);

    /**
     * @brief >> operator overload to be able to cin>> a Uint
     *
     * @param is input stream
     * @param s Sint
     * @return std::istream&
     */
    friend std::istream &operator>>(std::istream &is, Sint &s);

    // Artithmetic operator overloads
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
    Sint &operator-();

    // Boolean comparison operator overloads
    bool operator<(const Sint &right) const;
    bool operator<=(const Sint &right) const;
    bool operator>(const Sint &right) const;
    bool operator>=(const Sint &right) const;
    bool operator==(const Sint &right) const;
    bool operator!=(const Sint &right) const;

    /**
     * @brief Convert a Sint to a int64_t
     * 
     * @return int64_t
     */
    explicit operator int64_t() const;
};
#endif