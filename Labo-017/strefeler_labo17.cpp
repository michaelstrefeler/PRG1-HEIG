/*
    But: Utiliser la suite de syracuse pour aller du nombre --> 1
         Montrer le nombre d'opérations à faire pour aller --> 1
    Nom du fichier: strefeler_labo17.cpp
    Auteur: Michael Strefeler
    Date de création: 08.11.21
*/
#include <iostream>

using namespace std;

/**
 * @brief Suite de Syracuse
 *
 * @param show_values bool pour choisir si on veut voir les valeur ou non
 * @param user_value  valeur entrée par l'utilisateur
 * @return int iterations pour arriver à 1
 */
int syracuse(bool show_values, int user_value)
{
    int iterations = 0;
    while (user_value != 1)
    {
        if (user_value % 2 == 0)
        {
            user_value = user_value / 2;
        }
        else
        {
            user_value = user_value * 3 + 1;
        }
        if (show_values)
        {
            cout << user_value << " " << endl;
        }
        iterations++;
    }
    return iterations;
}

int main()
{
    int user_value;
    cout << "Mettez un nombre entre 1 et 10'000: ";
    cin >> user_value;
    cout << syracuse(true, user_value)
         << " Iterations pour arriver à 1" << endl;

    cout << "Mettez un deuxieme nombre entre 1 et 1000: ";
    cin >> user_value;

    // Boucle pour afficher le nombre d'iteration du 1 jusqu'à user_value
    for (int i = 1; i <= user_value; i++)
    {
        cout << "Nombre d'iteration pour " << i << ": "
             << syracuse(false, i) << endl;
    }
}