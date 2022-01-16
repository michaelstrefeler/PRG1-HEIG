#include "Sint.hpp"
#include "Uint.hpp"
#include <iostream>
#include <limits>
#include <functional>
#include <random>

using namespace std;

Uint randUint(size_t digits)
{
    auto gen_int = std::bind(std::uniform_int_distribution<int32_t>(0, 9),
                             std::mt19937(unsigned(time(NULL))));
    std::string rand;
    do
    {
        rand = std::to_string(gen_int());
    } while (rand == "0");

    for (size_t i = 0; i < digits - 1; ++i)
    {
        rand += std::to_string(gen_int());
    }
    return Uint(rand);
}

bool isPrime(Uint &prime, size_t size)
{
    if (size == 0)
        return false;

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
            Uint random = (randUint(size % uint64_t(prime))) + 1;
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

    Uint p = randUint(digits);
    Uint q = randUint(digits);
    size_t size;

    if (digits == 1)
    {
        size = 1;
    }
    else
    {
        size = digits - 1;
    }

    while (isPrime(p, size) == false)
    {
        p = randUint(digits);
    }

    while (isPrime(q, size) == false)
    {
        q = randUint(digits);
    }

    while(p == q){
        q -= 1;
        while (isPrime(q, size) == false)
        {
            q = randUint(digits);
        }
    }
    cout << p << " and " << q << endl;
    Uint phi = (p - 1) * (q - 1);
    Uint n = p * q;
    cout << "Phi: " << phi << " n: " << n << endl;
    Uint e = randUint(phi.getSize());
    Sint inverse;
    while (e > phi or euclidAlgo(Sint(phi), Sint(e), inverse) != 1)
    {
        Uint e = randUint(phi.getSize());
    }

    cout << "Public key (" << n << ", " << e << ")" << endl;
    cout << "Private key: " << inverse << endl;
}