/*
    But : Implémenter la méthode de cryptographie à clé publique RSA
    Nom du fichier : strefeler_labo16.cpp
    Auteur : Michael Strefeler
    Date de création : 25.10.21
*/
#include <iostream>
#include <functional>
#include <random>

using namespace std;

// Exponetiation modulaire
// base: base qu'on veut utiliser
// exposant: mettre la base à cet exposant 
// divisor: par quoi on veut diviser
long long modularExp(long long base, long long exposant, long long divisor)
{
    long long r = 1;
    while (exposant > 0)
    {
        if (exposant % 2 == 0)
        {
            base = (base * base) % divisor;
            exposant /= 2;
        }
        else
        {
            r = (r * base) % divisor;
            exposant -= 1;
        }
    }
    return r;
}

// Utilisé pour savoir si un int prime est premier
// int prime: le nombre potentiellement premier
// return true si prime est probablement premier
// sinon return false
bool isPrime(int prime)
{
    // Générateur de nombre aléatoire de < prime
    auto gen_int = bind(uniform_int_distribution<int>(1, prime - 1),
                        mt19937(92646));
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

// Plus grand diviseur commun de 2 nombres
// long long a: premier nombre
// long long b: deuxième nombre
long long gcd(long long a, long long b)
{
    // Boucle pour trouver le PGC
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }

    return a;
}

// Algorithme d'Euclide étendu
// int a: premier nombre
// int b: deuxième nombre
int euclidAlgo(int a, int b)
{
    int r = a;       // le PDGC de a et b
    int r_prime = b; // valeur temporaire
    int d = 0;       // l'inverse de b mod a
    int d_prime = 1; // valeur temporaire
    while (r_prime != 0)
    {
        int q = r / r_prime; // partie entière de r et r'
        int rs = r;
        int ds = d;
        r = r_prime;
        d = d_prime;
        r_prime = rs - q * r_prime;
        d_prime = ds - q * d_prime;
    }
    if (d < 0)
    {
        d = d + a;
    }
    return d;
}


int main()
{
    int p, q, e;
    cout << "Donnez-moi deux nombres premier distincts et un nombre premier < le produit des deux autres: ";
    cin >> p >> q >> e;

    // Vérifie que les nombres premiers sont distincts
    // Que p * q < 2^31 - 1 (valeur maximale du int)
    // Et vérifie que p et q sont premiers
    if (p != q and (p * q) < (pow(2, 31) - 1) and isPrime(p) and isPrime(q))
    {
        int x = (p - 1) * (q - 1);
        // Vérifie que e < (p - 1) * (q - 1), que e < 2^31-1
        // et que e est premier avec (p - 1) * (q - 1)
        if (e < x and e < (pow(2, 31) - 1) and gcd(e, x) == 1)
        {
            int n = p * q;
            int inverse = euclidAlgo(x, e);
            // Générateur de nombre aléatoire utilisée pour le message
            // Qui doit être < n
            auto gen_message = bind(uniform_int_distribution<int>(1, n - 1),
                                    mt19937(221099));
            int message = gen_message();
            // divisor^e mod n
            long long encrypted_message = modularExp(message, e, n);
            // (divisor^e mod n)^d mod n
            long long decrypted_message = modularExp(encrypted_message, inverse, n);

            cout << "Cle publique (" << n << ", " << e << "). Cle secrete: "
                 << inverse << endl;

            // Vérifie qu'on arrive à trouver le message avec le message chiffré
            cout << "Message : " << message
                 << " Message crypte : " << encrypted_message << endl
                 << "Message decrypte: " << decrypted_message << endl;
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