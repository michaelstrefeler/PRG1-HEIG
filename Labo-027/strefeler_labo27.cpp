/**
 * @file strefeler_labo27.cpp
 * @author Michael Strefeler
 * @brief Encrypt file with RSA
 * @version 0.1
 * @date 03-12-2021
 *
 * @copyright Copyright (c) 2021
 * a.exe < les_miserables.txt > out.txt
 */

#include <algorithm>
#include <climits>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <random>
#include <string>
#include <vector>

using namespace std;

const int32_t MAX_VALUE = numeric_limits<int32_t>::max(); // 2^31 - 1

// Modular exponentiation
// base: the base that we want to use
// exponent: exponent of the base
// divisor: what we're divding the rest by
// return: base^exposant mod divisor
int64_t modularExp(int64_t base, int64_t exponent, int64_t divisor)
{
    int64_t result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 0)
        {
            base = (base * base) % divisor;
            exponent /= 2;
        }
        else
        {
            result = (result * base) % divisor;
            exponent -= 1;
        }
    }
    return result;
}

// Used to check if a number is prime with high probability
// int prime: potentially prime number we want to test
// return: true if the number is prime and false if that's not the case
bool isPrime(int32_t prime)
{
    // Random number generator from 1 to prime - 1
    auto gen_int = bind(uniform_int_distribution<int32_t>(1, prime - 1),
                        mt19937(unsigned(time(NULL))));
    int32_t random;
    int64_t q, u;

    // 2 is the smallest prime number
    if (prime < 2)
    {
        return false;
    }
    if (prime == 2)
    {
        return true;
    }

    // Loop to find out if the number is prime with high probability
    for (int32_t i = 0; i < 10; ++i)
    {
        // Random number generated at each instance of the loop
        random = gen_int();

        // if random^p-1 % p != 1
        // modularExp is used to suppport numbers > 17
        if (modularExp(random, prime - 1, prime) != 1)
        {
            return false;
        }
        q = 1;
        u = prime - 1;

        while (u % 2 == 0 and q == 1)
        {
            u = u / 2;
            q = modularExp(random, u, prime);
            if (!q and q != (prime - 1))
            {
                return false;
            }
        }
    }
    return true;
}

// Extended euclid algorithm
// int a: first number
// int b: second number
// int& inverse: inverse of b mod a
// return: the Greatest common divisor of a and b
int32_t euclidAlgo(int32_t a, int32_t b, int32_t &inverse)
{
    int32_t gcd = a;
    int32_t gcd_prime = b;
    inverse = 0;
    int32_t inverse_prime = 1;
    while (gcd_prime != 0)
    {
        int32_t integer_part = gcd / gcd_prime;
        int32_t temp_gcd = gcd;
        int32_t temp_inverse = inverse;
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

/**
 * @brief Puts the int value of each char of the text into a vector
 *
 * @param words vector of words
 * @param text text to use
 */
void split_into_chars(vector<int> &chars, string text)
{
    for (size_t i = 0; i < text.length(); ++i)
    {
        chars.push_back(text.at(i));
    }
}

void encrypt_text(vector<uint32_t> &secret_text, vector<int> chars, int32_t e, int32_t n, int32_t inverse)
{
    for (size_t i = 0; i < chars.size(); ++i)
    {
        secret_text.push_back(modularExp(chars.at(i), e, n));
    }
}

void decrypt_text(string secret_text, string new_text, int32_t inverse, int32_t n)
{
    for (size_t i = 0; i < secret_text.size(); ++i){
        
    }
}

int main()
{
    vector<int> chars{};
    vector<uint32_t> secret_text{};
    string text;
    getline(std::ifstream("les_miserables.txt"), text, '\0');
    split_into_chars(chars, text);
    int32_t p, q, e, inverse;

    p = 30011;
    q = 30029;
    int32_t n = p * q;

    e = 31237;
    encrypt_text(secret_text, chars, e, n, inverse);

    // Put in file
    ofstream output_file("output.txt");
    for (size_t i = 0; i < secret_text.size(); ++i)
    {
        // Write to the file
        output_file << secret_text.at(i) << "00700";
    }

    // Close the file
    output_file.close();

    string encrypted_text;
    getline(std::ifstream("output.txt"), encrypted_text, '\0');

    vector<int32_t> encrypted{};
    string new_text = "";

    string secrets;
    getline(std::ifstream("output.txt"), secrets, '\0');
    
    decrypt_text(secrets, new_text, inverse, n);
}