/*
   Nom: Michael Strefeler
   Nom du fichier: strefeler_labo3.cpp
   But: Convertir secondes en semaines, jours, heures, minutes et secondes
   Date: 24/09/21
   Page: 1/1
*/
#include <iostream>
using namespace std;
int main()
{
    const int SEC_PER_MINUTE = 60;
    const int MIN_PER_HOUR = 60 * SEC_PER_MINUTE;
    const int HOUR_PER_DAY = 24 * MIN_PER_HOUR;
    const int DAY_PER_WEEK = 7 * HOUR_PER_DAY;

    int user_seconds, minutes, hours, days, weeks;
    
    cout << "\nConvertisseur de secondes en format plus clair: \n";

    cout << "\nMettez le nombre de secondes: ";
    cin >> user_seconds;
    
    // Calcul du nombre de semaines et le reste de secondes
    weeks = user_seconds / DAY_PER_WEEK;
    int seconds_left = user_seconds % DAY_PER_WEEK;

    // Calcul du nombre de jours et le reste de secondes
    days = seconds_left / HOUR_PER_DAY;
    seconds_left = seconds_left % HOUR_PER_DAY;

    // Calcul du nombre d'heures et le reste de secondes
    hours = seconds_left / MIN_PER_HOUR;
    seconds_left = seconds_left % MIN_PER_HOUR;

    // Calcul du nombre de minutes et le reste de secondes
    minutes = seconds_left / SEC_PER_MINUTE;
    seconds_left = seconds_left % SEC_PER_MINUTE;

    // Affiche la coversion
    cout << "Semaines: " << weeks << "\nJours: " << days << "\nHeures: " << hours << "\nMinutes: " << minutes << "\nSecondes: " << seconds_left;
    return 0;
}