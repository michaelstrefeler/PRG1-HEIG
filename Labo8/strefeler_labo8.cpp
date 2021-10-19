/*
    But: Calculer le volume d'une bouteille de lait
    Nom du fichier: strefeler_labo8.cpp
    Auteur: Michael Strefeler
    Date de création: 05.10.21
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Fonction trigo inverse pour récupérer PI
const double PI = atan2(0, -1);

int main(){
    double r1, r2, h1, h2, h3;
    double vol_small_cylinder, vol_trunc_cone, vol_big_cylinder, total_volume;

    cout << "Calcul du volume d'une bouteille de lait:" << endl
         << "Donnez moi r1, r2, h1, h2 et h3 (en cm) : ";
    cin >> r1 >> r2 >> h1 >> h2 >> h3;

    // Calcul volume cylindre du haut V = π * r^2 * h
    vol_small_cylinder = PI * pow(r1, 2) * h2;

    // Calcul volume cône tronqué V = (1/3) * π * h * (r1^2 + r2^2 + (r1 * r2))
    vol_trunc_cone = 1./3 * PI * h3 * (pow(r1, 2) + pow(r2, 2) + r1 * r2);

    // Calcul volume cylindre du bas
    vol_big_cylinder = PI * pow(r2, 2) * h1;

    // Calcul du volume total
    total_volume = vol_small_cylinder + vol_trunc_cone + vol_big_cylinder;

    // Conversion du volume en litres 1 mL = 1 cm^3
    total_volume /= 1000;

    cout << setprecision(1) << fixed;
    cout << "Le volume de cette bouteille est de " << total_volume << " litres";
}