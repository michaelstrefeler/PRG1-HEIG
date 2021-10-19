/*
    But: Monte Carlo pour trouver pi avec des random
    Nom du fichier: strefeler_labo13_1.cpp
    Auteur: Michael Strefeler
    Date de création: 18.10.21
*/
#include <iostream>
#include <iomanip>
#include <random>
#include <functional>

const int NUMBER_OF_THROWS = 1000000;

using namespace std;

int main()
{
    int iterator = 0;
    int circle_hits = 0, total_throws = 0;
    double impact_x, impact_y, center_distance, pi;
    auto gen_double = bind(uniform_real_distribution<double>(-1, 1), 
                           mt19937(69420));

    // Boucle pour lancer 1 million de fléchettes aux coordonnées aléatoires
    while(iterator < NUMBER_OF_THROWS){
        // Mets une valeure aléatoire aux coordonnées de l'impacts
        impact_x = gen_double();
        impact_y = gen_double();

        center_distance = impact_x * impact_x + impact_y * impact_y;

        // Si l'impact est dans le cercle
        if (center_distance <= 1)
        {
            ++circle_hits;
        }
        ++total_throws;

        pi = double(4 * circle_hits) / total_throws;
        ++iterator;
    }
    cout << fixed << setprecision(2);
    cout << "Valeur estimee de pi " << pi;
}