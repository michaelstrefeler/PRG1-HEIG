#include "Sint.hpp"
#include "Uint.hpp"
#include <iostream>
#include <limits>
#include <functional>
#include <random>

using namespace std;

/**
 * @brief generate a random Uint
 * Using a random_device a mersenne twister and a uniform int distribution
 * 
 * @param digits amount of digits the random number will have
 * @return Uint the randomly Uint
 */
Uint randUint(Uint digits)
{
    static random_device device;
    mt19937 generator(device());
    uniform_int_distribution<int> number(0, 9);

    string temp = to_string(number(generator));
    while (temp == "0")
    {
        temp = to_string(number(generator));
    }
    for (Uint i = 0; i < digits - 1; ++i)
    {
        temp += to_string(number(generator));
    }
    return Uint(temp);
}

/**
 * @brief Check if a Uint is prime with high probablity
 * 
 * @param prime the potentially prime number
 * @return true 
 * @return false 
 */
bool isPrime(Uint &prime)
{
    // an empty Uint won't be prime
    if (prime.getSize() == 0)
    {
        return false;
    }

    // 2 is the smallest prime number so any number less than 2 won't be prime
    if (prime < 2)
    {
        return false;
    }
    else if (prime == 2)
    {
        return true;
    }
    else
    {
        // Loop to find out if the number is prime with high probability
        for (int i = 0; i < 10; ++i)
        {
            // Random number generated at each instance of the loop
            Uint random = (randUint(Uint(prime.getSize()) % prime)) + 1;
            Uint exp = prime - 1;

            if (mod_pow(random, exp, prime) != 1)
                return false;

            Uint modExp = 1;
            while (exp.isEven() && modExp == 1)
            {
                exp /= 2;
                modExp = mod_pow(random, exp, prime);
                if (modExp != 1 && modExp != prime - 1)
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    size_t digits;
    cout << "How many digits do you want the prime numbers used in the key to have? ";
    cin >> digits;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // prime numbers that will be randomly generated
    Uint p = 0;
    Uint q = 0;

    // generate a random number until it's prime
    do
    {
        p = randUint(digits);
    } while (isPrime(p) == false);
    do
    {
        q = randUint(digits);
    } while (isPrime(q) == false);

    // both prime numbers can't be the same or the algorithm doesn't work
    if (p == q)
    {
        // make q a different prime number
        do
        {
            q = randUint(digits);
        } while (isPrime(q) == false);
    }

    Uint phi = (p - 1) * (q - 1);
    Uint n = p * q;
    Uint e = randUint(phi.getSize() - 1);
    Sint inverse;

    // make e a prime number < phi
    while (isPrime(e) == false)
    {
        e = randUint(phi.getSize() - 1);
    }

    euclidAlgo(Sint(phi), Sint(e), inverse);
    // Public and private keys
    cout << "Public key (" << n << ", " << e << ")" << endl;
    cout << "Private key: " << inverse << endl;
}