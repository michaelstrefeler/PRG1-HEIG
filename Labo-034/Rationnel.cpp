#include "Rationnel.hpp"
#include <iostream>

Rationnel::Rationnel() {}
Rationnel::Rationnel(const std::string &s)
{
    std::string temp = s;
    if(s.front() == '-'){
        negative = true;
        temp = temp.substr(1);
    }
    else
        negative = false;

    bool found_separator = false;
    for (auto i = temp.crbegin(); i != temp.crend(); ++i){
        if(found_separator == true){
            numerator.value.push_back(*i - 48U);
        }else{
            if (*i == '/' || *i == ',' || *i == '.')
            {
                found_separator = true;
            }
            else
            {
                denominator.value.push_back(*i - 48U);
            }
        }
    }
    if(numerator.getSize() == 0){
        numerator = denominator;
        denominator = 1;
    }
    else{
        simplify(*this);
    }
}

Rationnel Rationnel::simplify(Rationnel &fraction){
    Uint gcd = get_gcd(fraction.numerator, fraction.denominator);
    if(gcd != 0){
        fraction.numerator /= gcd;
        fraction.denominator /= gcd;
    }
    return fraction;
}

std::ostream &operator<<(std::ostream &out, const Rationnel &s){
    if(s.negative){
        out << "-";
    }

    if(s.denominator != 1){
        out << s.numerator << "/" << s.denominator;
    }else{
        out << s.numerator;
    }
    return out;
}