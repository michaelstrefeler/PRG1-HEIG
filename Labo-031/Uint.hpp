#ifndef UINT_HPP
#define UINT_HPP

#include <vector>
#include <string>

const uint32_t ASCII_ZERO = 48;

/**
 * @brief Unsigned ints of arbitrary size
 * 
 */
class Uint
{
private:
    std::vector<uint32_t> value;

    /**
     * @brief Carry function used for addition
     * 
     * @return Uint& the result of the addition
     */
    Uint &carry();
    
    /**
     * @brief Used for boolean comparison operator overloads
     *
     * @param left left hand side of comparison
     * @param right right hand side of comparison
     * @return int -1 if left < right, 0 if equal else 1
     */
    int comp(const Uint &left, const Uint &right) const;

    /**
     * @brief Remove unwanted zeros that appear after some arithmetics
     * 
     */
    void fixValue();

    /**
     * @brief Division for Unsigned ints
     * 
     * @param dividend 
     * @param divisor 
     * @param remainder 
     * @return Uint : the quotient
     */
    Uint division(const Uint &dividend, const Uint &divisor, Uint &remainder);

public:
    /**
     * @brief Construct a new Uint object
     * 
     */
    Uint();

    /**
     * @brief Construct a new Uint object
     * 
     * @param s string value
     */
    Uint(const std::string &s);

    /**
     * @brief Construct a new Uint object
     * 
     * @param u uint64_t
     */
    Uint(uint64_t u);

    /**
     * @brief Check if the value of a Uint is even
     * 
     * @return true 
     * @return false 
     */
    bool isEven() const;

    /**
     * @brief Get the Size of a Uint
     * 
     * @return uint32_t the size
     */
    uint32_t getSize() const;

    /**
     * @brief Modular exponentiation
     *
     * @param base the base that we want to use
     * @param exp exponent of the base
     * @param mod what we're divding the rest by
     * @return Uint base^exposant modulo mod
     */
    friend Uint mod_pow(Uint base, Uint exp, const Uint &mod);
    friend int compUint(const Uint &left, const Uint &right);
    friend class Sint;

    /**
     * @brief overload the multiplication operator
     *
     * @param left left hand side of multiplication
     * @param right right hand side of multiplication
     * @return Uint procuct
     */
    friend Uint operator*(uint32_t left, const Uint &right);

    /**
     * @brief << operator overload to be able to show the value of a Uint
     * 
     * @param out output stream
     * @param u Uint
     * @return std::ostream& 
     */
    friend std::ostream &operator<<(std::ostream &out, const Uint &u);

    /**
     * @brief >> operator overload to be able to cin>> a Uint
     * 
     * @param is input stream
     * @param u Uint
     * @return std::istream& 
     */
    friend std::istream &operator>>(std::istream &is, Uint &u);

    // Artithmetic operator overloads
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

    //Boolean comparison operator overloads
    bool operator<(const Uint &right) const;
    bool operator<=(const Uint &right) const;
    bool operator>(const Uint &right) const;
    bool operator>=(const Uint &right) const;
    bool operator==(const Uint &right) const;
    bool operator!=(const Uint &right) const;
    
    /**
     * @brief Convert a Uint to a uint64_t
     * 
     * @return uint64_t 
     */
    explicit operator uint64_t() const;
};

#endif