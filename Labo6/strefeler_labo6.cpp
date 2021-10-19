/*
    But: Calculer la temps d'un trajet. le départ et l'arrivée sont données
         par l'utilisateur. Aucun trajet > 24 heures
    Nom du fichier: strefeler_labo6.cpp
    Auteur: Michael Strefeler
    Date de création: 30.09.21
    Exemples de résultats: 
        17h31 à 19h20 = 1h49
        23h12 à 1h25 = 2h13
        23h00 à 23h00 = 24h
*/

#include <iostream>
#include <iomanip>

using namespace std;

const int MIN_PER_HOUR = 60;

int main(){

    // variables pour l'heure de départ
    int start_hour;
    int start_minutes;
    int start_time;

    // variables pour l'heure d'arrivée
    int end_hour;
    int end_minutes;
    int end_time;

    // variables pour temps de trajet
    int travel_time;
    int hours_traveled;
    int min_traveled;

    cout << "-----DEPART-----" << endl;
    cout << "Heure de depart: ";
    cin >> start_hour;
    cout << "Mettez les minutes aussi: ";
    cin >> start_minutes;

    cout << "-----ARRIVEE-----" << endl;
    cout << "Heure d'arrivee: ";
    cin >> end_hour;
    cout << "Mettez les minutes aussi: ";
    cin >> end_minutes;

    // Transformation de l'heure de départ et d'arrivée en minutes
    start_time = (start_hour * MIN_PER_HOUR) + start_minutes;
    end_time = (end_hour * MIN_PER_HOUR) + end_minutes;

    // Calcul du temps de trajet en heures et en minutes
    travel_time = ((end_time - start_time) + 24 * MIN_PER_HOUR) - MIN_PER_HOUR;
    min_traveled = (travel_time + MIN_PER_HOUR) % MIN_PER_HOUR;
    hours_traveled = (((travel_time - min_traveled) / MIN_PER_HOUR)  % 24) + 1;
    
    // Affichage du résultat
    cout << "Le trajet prendra "
         << hours_traveled
         << "h" << setw(2) << setfill('0') << min_traveled << endl;
}