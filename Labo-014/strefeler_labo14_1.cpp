/*
    But: Afficher le résultat d'une série harmonique de taille k de 4 manières
    Nom du fichier: strefeler_labo14_1.cpp
    Auteur: Michael Strefeler
    Date de création: 19.10.21
*/
#include <iostream>

using namespace std;

// Série harmonique de 1/1 + ... 1/k en float
float harmonic_float_asc(int k)
{
    float sum = 0.0f;
    for (int i = 1; i <= k; ++i)
    {
        sum += 1.0f / float(i);
    }
    return sum;
}

// Série harmonique de 1/k + 1/k-1 ... 1/1 en float
float harmonic_float_desc(int k)
{
    float sum = 0.0f;
    for (int i = k; i > 0; --i)
    {
        sum += 1.0f / float(i);
    }
    return sum;
}

// Série harmonique de 1/1 + ... 1/k en double
double harmonic_double_asc(int k)
{
    double sum = 0.0;
    for (int i = 1; i <= k; ++i)
    {
        sum += 1.0 / i;
    }
    return sum;
}

// Série harmonique de 1/k + 1/k-1 ... 1/1 en double
double harmonic_double_desc(int k)
{
    double sum = 0.0;
    for (int i = k; i > 0; --i)
    {
        sum += 1.0 / i;
    }
    return sum;
}

int main()
{
    int k;
    cout << "Combien de termes voulez-vous ? ";
    cin >> k;
    while(k <= 0){
        cerr << "\nErreur. La valeur saisie doit etre > 0 "<<
        "\nCombien de termes voulez-vous ? ";
        cin >> k;
    }
    // Affiche tous les résultats
    cout << "\nLa somme des " << k << " premiers termes de la serie vaut "
         << harmonic_float_asc(k) << " Float ascendant"
         << "\nLa somme des " << k << " premiers termes de la serie vaut "
         << harmonic_float_desc(k) << " Float descendant"
         << "\nLa somme des " << k << " premiers termes de la serie vaut "
         << harmonic_double_asc(k) << " double ascendant"
         << "\nLa somme des " << k << " premiers termes de la serie vaut "
         << harmonic_double_desc(k) << " double descendant";
}