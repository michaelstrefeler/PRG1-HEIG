/*
    But: afficher le résultat d'une série harmonique de taille k
    Nom du fichier: strefeler_labo14_1.cpp
    Auteur: Michael Strefeler
    Date de création: 19.10.21
*/
#include <iostream>

using namespace std;

int main()
{
    int k;
    double s = 0.0;
    cout << "Combien de termes voulez-vous ? ";
    cin >> k;
    while(k <= 0){
        cerr << "\nErreur. La valeur saisie doit etre > 0 "<<
        "\nCombien de termes voulez-vous ? ";
        cin >> k;
    }

    for(int i = k; i > 0; --i){
        s += 1.0/i;
    }
    cout << "La somme des "<< k << " premiers termes de la serie vaut " << s;
}