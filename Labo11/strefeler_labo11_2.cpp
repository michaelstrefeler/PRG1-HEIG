/*
    But: Calcul de moyenne et commentaire sur la moyenne
    Nom du fichier: strefeler_labo11_2.cpp
    Auteur: Michael Strefeler
    Date de création: 13.10.21
*/
#include <limits>
#include <iomanip>
#include <iostream>

using namespace std;

const double INSUFFICIENT_GRADE = 4.0;
const double OK_GRADE = 4.5;
const double GOOD_GRADE = 5.0;
const double VERY_GOOD_GRADE = 5.5;

int main(){

    double grade_1, grade_2, grade_3, grade_4;
    double average;
    cout << "Donnez-moi vous 4 notes au dixieme de point: ";
    cin >> grade_1 >> grade_2 >> grade_3 >> grade_4;
    
    // Vérifie les entrées
    if (not(cin >> grade_1 >> grade_2 >> grade_3 >> grade_4))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    average = (grade_1 + grade_2 + grade_3 + grade_4)/4;
    cout << "Moyenne = " << fixed << setprecision(1) << average;

    if (average < INSUFFICIENT_GRADE){
        cout << " - Insuffisant";
    }else if(average >= INSUFFICIENT_GRADE && average <= OK_GRADE){
        cout << " - Moyen";
    }else if(average >= OK_GRADE && average <= GOOD_GRADE){
        cout << " - Bien";
    }else if(average >= GOOD_GRADE && average <= VERY_GOOD_GRADE){
        cout << " - Tres bien";
    }else{
        cout << " - Excellent";
    }
}
