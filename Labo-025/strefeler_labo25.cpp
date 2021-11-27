/********************************************************************
Programme de pivotage pour systèmes avec 3 lignes et 4 colonnes
Permet de résoudre des systèmes de 3 équations à 3 inconnues.
Par exemple, pour résoudre le système:
  x +  y + z =  6
 2x - 3y + z = -5
 3x + 2y - z =  7
On introduit la matrice
 1  1  1  6
 2 -3  1 -5
 3  2 -1  7
et on pivote une fois dans chaque ligne et chaque colonne:
 0 0
 1 1
 2 2
La matrice transformée devrait être:
5.263158e-002 1.578947e-001 2.105263e-001 1.000000e+000
2.631579e-001 -2.105263e-001 5.263158e-002 3.000000e+000
6.842105e-001 5.263158e-002 -2.631579e-001 2.000000e+000
La dernière colonne donne la solution: x = 1, y = 3 et z = 2.
******************************************************************/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void imprime_ligne(vector<double> ligne)
{
    for (size_t j = 0; j < ligne.size(); j++)
        cout << scientific << ligne.at(j) << " ";
    cout << endl;
}

void imprime_matrice(vector<vector<double>> v)
{
    cout << "----------------------" << endl;
    for (size_t i = 0; i < v.size(); i++)
        imprime_ligne(v.at(i));
    cout << endl;
}

/*Opération de pivotage */
void pivote(vector<vector<double>> &v, size_t ligne, size_t colonne)
{
    size_t nb_lignes = v.size();
    size_t nb_colonnes = v.at(0).size();
    for (size_t i = 0; i < nb_lignes; i++)
    {
        if (i != ligne)
        {
            for (size_t j = 0; j < nb_colonnes; j++)
            {
                if (j != colonne)
                {
                    v[i][j] = (v[i][j] - 1 * (v[i][colonne] * v[ligne][j] / v[ligne][colonne]));
                }
            }
        }
    }

    for (size_t i = 0; i < nb_lignes; i++)
    {
        if (i != ligne)
        {
            v[i][colonne] = (-1 * (v[i][colonne] / v[ligne][colonne]));
        }
    }

    for (size_t j = 0; j < nb_colonnes; j++)
    {
        if (j != colonne)
        {
            v[ligne][j] = (v[ligne][j] / v[ligne][colonne]);
        }
    }

    v[ligne][colonne] = (1.0 / v[ligne][colonne]);
}

int main()
{
    size_t nb_lignes;
    size_t nb_colonnes;
    cout << "Mettez le nombre de lignes et de colonnes: ";
    cin >> nb_lignes >> nb_colonnes;
    vector<vector<double>> v(nb_lignes, vector<double>(nb_colonnes));

    /* Lecture des éléments de la matrice + vecteur */
    for (size_t i = 0; i < nb_lignes; i++)
    {
        for (size_t j = 0; j < nb_colonnes; j++)
        {
            cout << "Introduire l'element de la ligne " << i << " et de la colonne " << j << endl;
            cin >> v[i][j];
        }
    }

    /* Pivotages; arrêter le programme avec CTRL-C */
    while (1)
    {
        imprime_matrice(v);
        cout << "ligne et colonne du pivot\n";
        size_t i, j;
        cin >> i >> j;
        if (i < nb_lignes and j < nb_colonnes and v[i][j] != 0.0)
        {
            pivote(v, i, j);
        }
        else
        {
            cout << "pivot non valide!\n";
        }
    }
}