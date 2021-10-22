/*
    But: Afficher le PGDC de 2 nombres avec l'algorithme d'Euclide
    Nom du fichier: strefeler_labo15.cpp
    Auteur: Michael Strefeler
    Date de création: 20.10.21
*/
#include <iostream>
#include <cmath>

using namespace std;

// PDGC de 2 int
int gcd_euclid(int divisor_1, int divisor_2)
{
    while (divisor_1 != divisor_2)
    {
        if (divisor_1 > divisor_2)
            divisor_1 -= divisor_2;
        else
            divisor_2 -= divisor_1;
    }
    return divisor_1;
}

// Exponetiation modulaire
// int b: base
// int e: exposant
// int m: modulo
int gdc_modular_exp(int b, int e, int m)
{
    int r = 1;
    while (e > 0)
    {
        if (e % 2 == 0)
        {
            b = (b * b) % m;
            e /= 2;
        }
        else
        {
            r = (r * b) % m;
            e -= 1;
        }
    }
    return r;
}

int main()
{
    int a, b, c;
    cout << "Donnez-moi deux entiers > 0 pour trouver leur PGDC: ";
    cin >> a >> b;

    // Vérification de l'entrée de l'utilisateur
    while (a <= 0 or b <= 0)
    {
        cout << "2 entiers > 0 SVP: ";
        cin >> a >> b;
    }
    
    cout << "Le PGDC de " << a << " et " << b << " est " << gcd_euclid(a, b);
    cout << "\n3 entier > 0 SVP pour trouver leur exponentiation modulaire: ";
    cout << "\nBase, exponsant, modulo : ";
    cin >> a >> b >> c;
    while (a <= 0 or b <= 0 or c <= 0)
    {
        cout << "\n3 entiers > 0 SVP: ";
        cin >> a >> b >> c;
    }
    cout << "\nExponentiation modulaire de  " << a << ", " << b << " et "
         << c << " est " << gdc_modular_exp(a, b, c);
}