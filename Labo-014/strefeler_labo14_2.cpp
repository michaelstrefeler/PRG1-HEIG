/*
    But: PPMC de deux entiers données par l'utilisateur
    Nom du fichier: strefeler_labo14_2.cpp
    Auteur: Michael Strefeler
    Date de création: 20.10.21
*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a, b;
    int pgdc, ppmc;

    cout << "Donnez-moi deux entiers > 0 pour trouver leur PPMC: ";
    cin >> a >> b;
    
    // Vérification de l'entrée de l'utilisateur
    while(a <= 0 or b <= 0){
        cout << "2 entiers > 0 SVP: ";
        cin >> a >> b;
    }

    // Variables pour PGDC
    int divisor_1 = a;
    int divisor_2 = b;

    // Boucle pour trouver le PGC
    while (divisor_1 != divisor_2)
    {
        if (divisor_1 > divisor_2)
            divisor_1 -= divisor_2;
        else
            divisor_2 -= divisor_1;
    }

    pgdc = divisor_1;

    /* ppmc(a,b) = | a * b | / pgdc(a,b) 
       dans ce programme a && b > 0 donc pas besoin de la valeur absolue */
    ppmc = (a*b)/pgdc;

    // Affiche le résultat
    cout << "le PPMC de " << a << " et " << b << " est : " << ppmc;
}