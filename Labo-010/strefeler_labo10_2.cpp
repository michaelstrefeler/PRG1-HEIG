/*
    But: Affiche le nombre le plus petit de 3 ints données par l'utilisateur
    Nom du fichier: strefeler_labo10_2.cpp
    Auteur: Michael Strefeler
    Date de création: 12.10.21
*/
#include <iostream>

using namespace std;

int main(){
    int a,b,c;
    cout << "Donnez-moi 3 ints: ";
    cin >> a >> b >> c;

    /* Structure if normale pour trouver le plus petit 
    if(a < b && a < c){
        cout << a;
    }else if(b < a && b < c){
        cout << b;
    }else{
        cout << c;
    }
    */

    /* 
        Ternaire pour trouver le minimum
        si a plus petit que b et plus petit que c
        sinon si b plus petit que a et plus petit que c
        sinon c est le plus petit
    */
    int min = a < b && a < c ? a : b < a && b < c ?  b : c;
    cout << endl << "Le plus petit chiffre est " << min;
}