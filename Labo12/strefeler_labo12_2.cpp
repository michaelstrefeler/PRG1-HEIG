/*
    But: Afficher les nombres de 20 à 1 par lots de trois
    Nom du fichier: strefeler_labo12_2.cpp
    Auteur: Michael Strefeler
    Date de création: 13.10.21
*/
#include <iomanip>
#include <iostream>

using namespace std;

const int MAX_NUMBER = 20;
const int NUMBERS_PER_LINE = 3;

int main()
{
    for (int i = MAX_NUMBER; i > 0; --i)
    {
        if ((i + 1) % NUMBERS_PER_LINE == 0 && i != MAX_NUMBER)
        {
            cout << endl;
        }
        cout << setw(NUMBERS_PER_LINE) << i;
    }

    cout << endl
         << endl;

    int i = MAX_NUMBER;
    while (i > 0)
    {
        if ((i + 1) % NUMBERS_PER_LINE == 0 && i != MAX_NUMBER)
        {
            cout << endl;
        }
        cout << setw(NUMBERS_PER_LINE) << i--;
    }
}