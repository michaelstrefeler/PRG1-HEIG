/*
   Nom: Michael Strefeler
   Nom du fichier: strefeler_labo2.cpp
   Date: 22/09/21
   Page: 1/1
*/
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    // Déclaration  des variables
    string name;
    int age;
    int current_year;

    time_t t = time(NULL);
	tm* timePtr = localtime(&t);
    current_year= timePtr->tm_year + 1900; // Prendre l'année actuelle

    cout << "\nMettez votre prenom:  ";
    getline (cin, name);

    cout << "\nMettez votre age: ";
    cin >> age;
    
    cout << "Bonjour " << name << ", Vous etes ne(e) en " << current_year - age << ".";
    return 0;
}
