/*
    But: Conversion Celsius à Fahrenheit et vice versa
    Nom du fichier: strefeler_labo9.cpp
    Auteur: Michael Strefeler
    Date de création: 05.10.21
*/

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main(){
    char choice;
    double degrees;
    double result;


    cout << "Transformation Fahrenheit <-> Degre Celsius" << endl
         << "Introduire le sens de la transformation (vers C ou F) : ";
    cin >> choice;

    // Conditions pour le choix de l'utilisateur
    if (choice == 'C' || choice == 'c')
    {
        cout << "Nombre de Fahrenheit: ";
        cin >> degrees;

        // Calcul conversion 5*(°F – 32)/9
        result = 5 * (degrees - 32) / 9;

        cout << setprecision(1) << fixed;
        cout << degrees << " Fahrenheit font " << result << " Celsius";

    }else if (choice == 'F' || choice == 'f'){
        cout << "Nombre de Celsius: ";
        cin >> degrees;
        // Calcul conversion  9/5°C + 32 = °F
        result = degrees * 9 / 5 + 32;

        cout << setprecision(1) << fixed;
        cout << degrees << " Celsius font " << result << " Fahrenheit";

    }else{ //Choix faux
        cout << "Erreur: Vous avez mal fait votre choix" << endl;
        exit(EXIT_FAILURE);
    }
}