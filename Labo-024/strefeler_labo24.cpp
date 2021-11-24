// This code was made with a 3 user liveshare so it might not work and I didn't make it all
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/**
 * @brief Gestion de l'entree utiisateur
 *
 * @param entree
 */
void entreeUtilisateur(int &entree)
{
    do
    {
        cout << "Entrez une nombre impaire et > 0 : ";
        cin >> entree;

    } while (entree < 0 || !(entree % 2));
}

bool estImpair(int i) { return i % 2; }

void afficherTableau(vector<int> v1)
{
    cout << "[";
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i);

        if (i < v1.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]";
}

void afficherTableau2D(vector<vector<int>> v1)
{
    cout << "{";
    for (int i = 0; i < v1.size(); i++)
    {
        afficherTableau(v1.at(i));
        cout << endl;
    }
    cout << "}";
}

void Ex524()
{
    cout << "Ex5.24" << endl;
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5};
    vector<int> vf;

    vf.resize(v1.size() + v2.size());
    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vf.begin());
    afficherTableau(vf);
}

void Ex526()
{
    cout << "Ex5.26" << endl;
    int tab[5] = {3, 2, -5, 2, 4};
    vector<int> v1 = {};

    size_t size = sizeof(tab) / sizeof(tab[0]);
    for (int i = 0; i < size; i++)
    {
        v1.push_back(tab[i]);
    }
    cout << "Le vecteur v initial : " << endl;
    afficherTableau(v1);
    cout << "La plus petite valeur de v : "
         << *min_element(v1.begin(), v1.end()) << endl;
    cout << "La plus grande valeur de v : "
         << *max_element(v1.begin(), v1.end()) << endl;
    cout << "La somme des elements de v : "
         << accumulate(v1.begin(), v1.end(), 0) << endl;
    cout << "Nombre d'occurrences de la valeur 2 dans v : "
         << count(v1.begin(), v1.end(), 2) << endl;
    cout << "Nombre de valeurs impaires dans v : "
         << count_if(v1.begin(), v1.end(), estImpair) << endl;
    sort(v1.begin(), v1.end());
    cout << "Le vecteur v trie croissant : " << endl;
    afficherTableau(v1);
    cout << endl;
    sort(v1.rbegin(), v1.rend());
    cout << "Le vecteur v trie decroissant : " << endl;
    afficherTableau(v1);
    cout << endl;
}

void carreMagique()
{
    int entree = 0;

    entreeUtilisateur(entree);

    int noLigne = entree - 1;
    int noColonne = entree / 2;

    vector<vector<int>> carreMagique(entree, vector<int>(entree));

    for (int k = 1; k <= entree * entree; k++)
    {
        carreMagique.at(noLigne).at(noColonne) = k;

        if (carreMagique.at((noLigne + 1) % entree).at((noColonne + 1) % entree) != 0)
        {
            if (noLigne == 0)
                noLigne = entree - 1;
            else
                noLigne--;
        }
        else
        {
            noLigne++;
            if (noLigne == entree)
                noLigne = 0;

            noColonne++;
            if (noColonne == entree)
                noColonne = 0;
        }
    }

    afficherTableau2D(carreMagique);
}

/**
 * @brief Exercice 5.25 égalité 2 vectors
 *
 * @param v1 vector 1
 * @param v2 vector 2
 */
void Ex525(vector<int> v1, vector<int> v2)
{
    cout << "Ex5.25" << endl;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    cout << boolalpha << includes(v1.begin(), v1.end(), v2.begin(), v2.end()) << endl;
}

void Ex527()
{
    cout << "Ex5.27" << endl;
    vector<string> v = {"Pierre", "Pierre", "Pierre", "Paul", "Jacques", "Jacques", "Henri", "Pierre", "Paul", "Jacques"};
    for (size_t i = 0; i < v.size(); ++i)
    {
        if (v.at(i) == "Paul")
        {
            cout << "Paul en position " << i << endl;
        }
        if (v.at(i) == "Henri")
        {
            cout << "Henri en position " << i << endl;
        }
    }

    for (size_t i = 0; i < v.size(); ++i)
    {
        if (v.at(i) == "Pierre" and v.at(i + 1) == "Paul" and v.at(i + 2) == "Jacques")
        {
            cout << "Le motif [Pierre, Paul, Jacques] en position " << i << endl;
        }
    }
}

int main()
{
    Ex524();
    cout << endl;
    Ex525({3, 3, 1, 1, 2, 1}, {1, 2, 3});
    cout << endl;
    Ex526();
    cout << endl;
    Ex527();
    carreMagique();
}
