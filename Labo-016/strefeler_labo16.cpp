/*
    But : Implanter la méthode de cryptographie à clé publique RSA
    Nom du fichier : strefeler_labo16.cpp
    Auteur : Michael Strefeler
    Date de création : 25.10.21
*/
#include <iostream>
#include <functional>
#include <random>

using namespace std;

const int MAX_VALUE = pow(2, 31) - 1; // 2^31 - 1

// Exponetiation modulaire
// base: base qu'on veut utiliser
// exponent: mettre la base à cet exposant
// divisor: par quoi on veut diviser
// return: base^exposant mod divisor
long long modularExp(long long base, long long exponent, long long divisor)
{
    long long result = 1;
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

// Utilisé pour savoir si un int prime est premier
// int prime: le nombre potentiellement premier
// return:  true si prime est probablement premier sinon false
bool isPrime(int prime)
{
    // Générateur de nombre aléatoire de < prime
    auto gen_int = bind(uniform_int_distribution<int>(1, prime - 1),
                        mt19937(22101999));
    int random;
    long long q, u;

    // 2 est le plus petit nombre premier
    if (prime < 2)
    {
        return false;
    }
    if (prime == 2)
    {
        return true;
    }

    // Boucle pour trouver si le nombre est probablement premier
    for (int i = 0; i < 10; ++i)
    {
        // Nombre aléatoire généré à chaque instance de la boucle
        random = gen_int();

        // si aléatoire^p-1 divisor p != 1
        // modularExp est utilisé
        // sinon cette fonction ne marche pas avec des nombres > 17
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

// Algorithme d'Euclide étendu
// int a: premier nombre
// int b: deuxième nombre
// int& inverse: l'inverse de b mod a
// return: le PGDC des deux nombres
int euclidAlgo(int a, int b, int& inverse)
{
    int gcd = a;           // le PDGC de a et b
    int gcd_prime = b;
    inverse = 0;       // l'inverse de b mod a
    int inverse_prime = 1;
    while (gcd_prime != 0)
    {
        int integer_part = gcd / gcd_prime; // partie entière de r et r'
        int temp_gcd = gcd;
        int temp_inverse = inverse;
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
    int p, q, e;
    cout << "Donnez-moi deux nombres premier distincts et un nombre premier < le produit des deux autres: ";
    cin >> p >> q >> e;

    // Vérifie que les nombres premiers sont distincts
    // Que p * q < 2^31 - 1 (valeur maximale du int)
    // Et vérifie que p et q sont premiers
    if (p != q and (p * q) < MAX_VALUE and isPrime(p) and isPrime(q))
    {
        int x = (p - 1) * (q - 1);

        // Vérifie que e < (p - 1) * (q - 1), que e < 2^31-1
        // et que e est premier avec (p - 1) * (q - 1)
        int inverse;
        if (e < x and e < MAX_VALUE and euclidAlgo(x, e, inverse) == 1)
        {
            int n = p * q;

            // Générateur de nombre aléatoire utilisée pour le message
            // Qui doit être < n
            auto gen_message = bind(uniform_int_distribution<int>(1, n - 1),
                                    mt19937(22101999));

            cout << "\nCle publique (" << n << ", " << e << "). Cle secrete: "
                 << inverse << endl;
            for (int i = 0; i < 10; i++)
            {
                int message = gen_message();

                // message^e mod n
                long long encrypted_message = modularExp(message, e, n);

                // (message^e mod n)^d mod n
                long long decrypted_message = modularExp(encrypted_message,
                                                         inverse, n);

                // Vérifie qu'on arrive à retrouver le message
                cout << "\nMessage : " << message
                     << " Message crypte : " << encrypted_message << endl
                     << "Message decrypte: " << decrypted_message << endl;
            }
        }
        else
        {
            // Affiche ce message quand l'utilisateur fait une erreur
            cerr << "Essayez de nouveau" << endl;
            return EXIT_FAILURE; // Ferme le programme
        }
    }
    else
    {
        // Affiche ce message quand l'utilisateur fait une erreur
        cerr << "Essayez de nouveau" << endl;
        return EXIT_FAILURE; // Ferme le programme
    }
}