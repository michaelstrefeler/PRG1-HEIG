/*
    But: Afficher les limites des types
    Nom du fichier: sttrefeler_labo4.cpp
    Auteur: Michael Strefeler
    Date: 28.09.21
    Page: 1/1
*/
#include <iostream>
#include <limits>

using namespace std;

int main(){
    // Signés
    cout << "Signed types:\n";
    cout << "signed char (" << sizeof(signed char)*8 << " bits) " 
         << int(numeric_limits<signed char>::lowest()) << " -> "
         << int(numeric_limits<signed char>::max()) << "\n";

    cout << "signed short int (" << sizeof(signed short) * 8 << " bits) "
         << numeric_limits<signed short>::lowest() << " -> "
         << numeric_limits<signed short>::max() << "\n";

    cout << "signed int (" << sizeof(signed int) * 8 << " bits) "
         << numeric_limits<signed int>::lowest() << " -> "
         << numeric_limits<signed int>::max() << "\n";

    cout << "signed long int (" << sizeof(signed long) * 8 << " bits) "
         << numeric_limits<signed long>::lowest() << " -> "
         << numeric_limits<signed long>::max() << "\n";

    cout << "signed long long int (" << sizeof(signed long long) * 8 << " bits) "
         << numeric_limits<signed long long>::lowest() << " -> "
         << numeric_limits<signed long long>::max() << "\n\n";

    // Non signés
    cout << "Unisgned types:\n";
    cout << "unsigned char (" << sizeof(unsigned char) * 8 << " bits) "
         << int(numeric_limits<unsigned char>::lowest()) << " -> "
         << int(numeric_limits<unsigned char>::max()) << "\n";

    cout << "unsigned short int (" << sizeof(unsigned short) * 8 << " bits) "
         << numeric_limits<unsigned short>::lowest() << " -> "
         << numeric_limits<unsigned short>::max() << "\n";

    cout << "unsigned int (" << sizeof(unsigned int) * 8 << " bits) "
         << numeric_limits<unsigned int>::lowest() << " -> "
         << numeric_limits<unsigned int>::max() << "\n";

    cout << "unsigned long int (" << sizeof(unsigned long) * 8 << " bits) "
         << numeric_limits<unsigned long>::lowest() << " -> "
         << numeric_limits<unsigned long>::max() << "\n";

    cout << "unsigned long long int (" << sizeof(unsigned long long) * 8 << " bits) "
         << numeric_limits<unsigned long long>::lowest() << " -> "
         << numeric_limits<unsigned long long>::max() << "\n\n";

    // Nombres Réels
    cout << "Real Number Types:\n";
    cout << "float (" << sizeof(float) * 8 << " bits) "
         << numeric_limits<float>::lowest() << " -> "
         << numeric_limits<float>::max() << "\n";

    cout << "double(" << sizeof(double) * 8 << " bits) "
         << numeric_limits<double>::lowest() << " -> "
         << numeric_limits<double>::max() << "\n";

    cout << "long double(" << sizeof(long double) * 8 << " bits) "
         << numeric_limits<long double>::lowest() << " -> "
         << numeric_limits<long double>::max() << "\n\n";
}