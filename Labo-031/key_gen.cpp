#include "Sint.hpp"
#include "Uint.hpp"
#include <iostream>
#include <limits>
#include <functional>
#include <random>

using namespace std;

Uint randUint(size_t digits)
{
    static random_device device;
    mt19937 generator(device());
    uniform_int_distribution<int> number(0, 9);

    string temp = to_string(number(generator));
    while (temp == "0")
    {
        temp = to_string(number(generator));
    }
    for (size_t i = 0; i < digits - 1; ++i)
    {
        temp += to_string(number(generator));
    }
    return Uint(temp);
}

bool isPrime(Uint &prime)
{
    if (prime.getSize() == 0)
    {
        return false;
    }

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
        for (int i = 0; i < 10; ++i)
        {
            Uint random = (randUint(prime.getSize() % uint64_t(prime))) + 1;
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

    Uint p = 0;
    Uint q = 0;
    size_t size;

    if (digits == 1)
    {
        size = 1;
    }
    else
    {
        size = digits - 1;
    }

    do
    {
        p = randUint(digits);
    } while (isPrime(p) == false);

    do
    {
        q = randUint(digits);
    } while (isPrime(q) == false);

    if (p == q)
    {
        do
        {
            q = randUint(digits);
        } while (isPrime(q) == false);
    }
    Uint phi = (p - 1) * (q - 1);
    Uint n = p * q;
    Uint e = randUint(phi.getSize() - 1);
    Sint inverse;

    while (isPrime(e) == false)
    {
        e = randUint(phi.getSize() - 1);
    }

    euclidAlgo(Sint(phi), Sint(e), inverse);
    cout << (euclidAlgo(Sint(phi), Sint(e), inverse) != 1);
    cout << "Public key (" << n << ", " << e << ")" << endl;
    cout << "Private key: " << inverse << endl;
}