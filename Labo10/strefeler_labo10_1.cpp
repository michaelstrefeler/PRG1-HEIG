/*
    But: Dire à l'utilisateur le nombre de jours dans le mois donné
    Nom du fichier: strefeler_labo10_1.cpp
    Auteur: Michael Strefeler
    Date de création: 12.10.21
*/
#include <iostream>

using namespace std;

int main(){
    int month;
    int days_in_month;
    cout << "Entrez un no de mois (1-12) : ";
    cin >> month;

    /* 
        Si le mois est un des mois ayant 30 jours nombre de jours = 30
        sinon regarde si le mois c'est février mets à 28 jours sinon 31 jours
    */
    days_in_month = month == (4 || 6 || 9 || 11) ? 30 : month == 2 ? 28 : 31;
    cout << "Ce mois comporte " << days_in_month << " jours.";
}