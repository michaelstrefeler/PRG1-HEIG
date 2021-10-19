/*
    But: Trier 3 int par ordre croissant
    Nom du fichier: strefeler_labo10_3.cpp
    Auteur: Michael Strefeler
    Date de création: 12.10.21
*/
#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cout << "Donnez-moi 3 ints: ";
    cin >> a >> b >> c;
    
    // Structure de if pour trier
    if (a < c && c < b && b > a)
    {
        cout << a << " " << c << " " << b;
    }
    else if (b < a && a < c && c > a)
    {
        cout << b << " " << a << " " << c;
    }
    else if (b < a && c < a && c > b)
    {
        cout << b << " " << c << " " << a;
    }
    else if (c < a && a < b && b > c)
    {
        cout << c << " " << a << " " << b;
    }
    else if (c < b && b < a && a > c)
    {
        cout << c << " " << b << " " << a;
    }
    else
    {
        cout << a << " " << b << " " << c;
    }
}