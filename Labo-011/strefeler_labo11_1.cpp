/*
    But: Dire si un nombre est multiple de 3 et/ou de 5
    Nom du fichier: strefeler_labo11_1.cpp
    Auteur: Michael Strefeler
    Date de création: 13.10.21
*/
#include <iostream>

using namespace std;

const int FIRST_DIVISOR = 3;
const int SECOND_DIVISOR = 5;

int main()
{
    int number;
    cout << "Donnez moi un entier >= 0: ";
    cin >> number;

    /*
        <n> est un multiple de 3 
        <n> est un multiple de 5 
        <n> est un multiple de 3 et de 5 
        <n> n'est ni un multiple de 3 ni un multiple de 5 
    */
    if(number % FIRST_DIVISOR == 0 && number){
        cout << number << " est un multiple de " << FIRST_DIVISOR;
        if (number % SECOND_DIVISOR == 0)
        {
            cout << " et de " << SECOND_DIVISOR;
        }
   }else if(number % SECOND_DIVISOR == 0 && number){
       cout << number << " est un multiple de " << SECOND_DIVISOR;
   }else{
       cout << number << " n'est ni multiple de " << FIRST_DIVISOR
            << " ni un multiple de 5";
   }

}