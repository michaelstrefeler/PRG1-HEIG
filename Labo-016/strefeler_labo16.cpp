/*
    Goal : Implement the RSA public key cryptosystem
    File name : strefeler_labo16.cpp
    Author : Michael Strefeler
    Creation date : 25.10.21
*/
#include <climits>
#include <iostream>
#include <functional>
#include <time.h>
#include <random>

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
int32_t euclidAlgo(int32_t a, int32_t b, int32_t& inverse)
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

int main()
{
    int32_t p, q, e, inverse;
    cout << "Enter two prime numbers: ";
    cin >> p >> q;

    // User data entry validation for the two prime numbers
    while(p == q or p * q > MAX_VALUE or !isPrime(p)or !isPrime(q)){
        cout << "Enter two prime numbers: ";
        cin >> p >> q;
    }
    
    int32_t phi = (p - 1) * (q - 1);
    int32_t n = p * q;
    
    cout<< "\nEnter a number coprime to (p-1)(q-1): ";
    cin >> e;

    // User data validation for the coprime number
    while(e > phi or euclidAlgo(phi, e, inverse) != 1){
        cout << "\nEnter a number coprime to (p-1)(q-1): ";
        cin >> e;
    }

    // Random number generator for the message < n with a distinct seed
    auto gen_message = bind(uniform_int_distribution<int32_t>(1, n - 1),
                            mt19937(unsigned(time(NULL))));

    cout << "\nPublic key (" << n << ", " << e << ")\nPrivate key: "
         << inverse << endl;
    for (int32_t i = 1; i < 11; i++)
    {
        int32_t message = gen_message();

        // message^e mod n
        int64_t encrypted_message = modularExp(message, e, n);

        // (message^e mod n)^d mod n
        int64_t decrypted_message = modularExp(encrypted_message,
                                               inverse, n);

        // Checks that we can decrypt the message
        cout << "\nMessage " << i << ": " << message
             << "\nEncrypted message " << i << ": " << encrypted_message << endl
             << "Decrypted message: " << i << ": " << decrypted_message << endl;
    }
}