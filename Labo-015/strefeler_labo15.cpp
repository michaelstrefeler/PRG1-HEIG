/*
    But: Afficher le PGDC de 2 nombres avec l'algorithme d'Euclide
    Nom du fichier: strefeler_labo15.cpp
    Auteur: Michael Strefeler
    Date de création: 20.10.21
*/
#include <iostream>

using namespace std;

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

int gdc_modular_exp(int a, int b)
{
    /*Input: b; e;m
    Result: r = be mod m
    r   1
    while e > 0 do
    if e mod 2 = 0 then
    b   b2 mod m; e   e=2
    else
    r   r <-- b mod m; e   e <-- 1
    end*/
    return 0;
}

int main()
{
    int a, b;
    cout << "Donnez-moi deux entiers > 0 pour trouver leur PGDC: ";
    cin >> a >> b;

    // Vérification de l'entrée de l'utilisateur
    while (a <= 0 or b <= 0)
    {
        cout << "2 entiers > 0 SVP: ";
        cin >> a >> b;
    }

    cout << "Le PGDC de " << a << " et " << b << " est " << gcd_euclid(a, b);
    cout << "\nLe PGDC de " << a << " et " << b << " est " << gdc_modular_exp(a, b);
}