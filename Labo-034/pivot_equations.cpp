#include "Rationnel.hpp"
#include "Uint.hpp"
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

template <typename T>
void imprime_ligne(const vector<T> ligne)
{
    for (size_t j = 0; j < ligne.size(); j++)
        cout << scientific << ligne.at(j) << " ";
    cout << endl;
}

template <typename T>
void imprime_matrice(const vector<vector<T>> t)
{
    cout << "----------------------" << endl;
    for (size_t i = 0; i < t.size(); i++)
        imprime_ligne(t.at(i));
    cout << endl;
}

/*Opération de pivotage */
template <typename T>
void pivote(vector<vector<T>> &t,
            size_t ligne, size_t colonne, int nbreLignes, int nbreColonnes)
{
    for (size_t i = 0; i < nbreLignes; i++)
        if (i != ligne)
            for (size_t j = 0; j < nbreColonnes; j++)
                if (j != colonne)
                    t.at(i).at(j) = t.at(i).at(j) - t.at(i).at(colonne) * t.at(ligne).at(j) / t.at(ligne).at(colonne);

    for (size_t i = 0; i < nbreLignes; i++)
        if (i != ligne)
            t.at(i).at(colonne) = -t.at(i).at(colonne) / t.at(ligne).at(colonne);

    for (size_t j = 0; j < nbreColonnes; j++)
        if (j != colonne)
            t.at(ligne).at(j) = t.at(ligne).at(j) / t.at(ligne).at(colonne);
    t.at(ligne).at(colonne) = T(1.0) / t.at(ligne).at(colonne);
}

void TailleMatrice(int &nbreColonnes, int &nbreLignes, int valeur)
{
    nbreColonnes = valeur + 1;
    nbreLignes = valeur;
}

void entreeUtilisateur(int &entree)
{
    do
    {
        cout << "Taille du systeme : ";
        cin >> entree;

    } while (entree < 1);
}

int main(void)
{
    int entree;
    entreeUtilisateur(entree);

    int nbreColonnes;
    int nbreLignes;

    TailleMatrice(nbreColonnes, nbreLignes, entree);

    // vector<vector<long double>> t(nbreLignes, vector<long double>(nbreColonnes));
    vector<vector<Rationnel>> t(nbreLignes, vector<Rationnel>(nbreColonnes));

    for (size_t i = 0; i < nbreLignes; i++)
        for (size_t j = 0; j < nbreColonnes; j++)
        {
            cout << "Introduire l'element de la ligne " << i
                 << " et de la colonne " << j << endl;
            cin >> t.at(i).at(j);
        }

    while (1)
    {
        imprime_matrice(t);
        cout << "ligne et colonne du pivot\n";
        size_t i, j;
        cin >> i >> j;
        if ((i < nbreLignes) && (j < nbreColonnes) && (t.at(i).at(j) != 0.0))
            pivote(t, i, j, nbreLignes, nbreColonnes);
        else
            cout << "pivot non valide!\n";
    }

    //-17296897026448322897687/60214--42507/30107*31111699833335825140475/1771/362739/4301
    /*Rationnel a("-17296897026448322897687/60214");
    Rationnel b("-42507/30107");
    Rationnel c("31111699833335825140475/1771");
    Rationnel d("362739/4301");
    Rationnel sub = a - b;
    Rationnel mult = sub * c;
    Rationnel final = mult / d;
    cout << final << endl;*/
}