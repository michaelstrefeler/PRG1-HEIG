/*
    But: Addition longueurs. Utilisteur entre km, m, cm, mm et on calcule 
         la distance
    Nom du fichier: strefeler_labo7.cpp
    Auteur: Michael Strefeler
    Date de création: 04.10.21
*/

#include <iostream>

using namespace std;

const int MM_PER_CM = 10;
const int CM_PER_M = 100;
const int M_PER_KM = 1000;

int main()
{
    int km;
    int m;
    int cm;
    int mm;

    int km_2;
    int m_2;
    int cm_2;
    int mm_2;

    int km_tot;
    int m_tot;
    int cm_tot;
    int mm_tot;

    // Demande des distances à l'utilisateur
    cout << endl << "Entrez des km m cm et mm : ";
    cin >> km >> m >> cm >> mm;
    cout << "Mettez les km m cm et mm a additioner: ";
    cin >> km_2 >> m_2>> cm_2 >> mm_2;

    // Affichage du calcul
    cout << endl
         << km << "km, " << m << "m, " << cm << "cm, " << mm << "mm et "
         << km_2 << "km, " << m_2 << "m, " << cm_2 << "cm, "
         << mm_2 << "mm font :"<< endl;
    
    // Calcul des distances
    mm_tot = (mm + mm_2);
    cm_tot = (cm + cm_2);
    m_tot = (m + m_2);
    km_tot = km + km_2;

    cm_tot = (cm_tot + mm_tot % MM_PER_CM);
    m_tot = (m_tot + cm_tot / CM_PER_M);
    km_tot += m_tot / M_PER_KM;

    // Affichage du résultat
    cout << km_tot << "km, " << m_tot % M_PER_KM << "m, "
         << cm_tot % CM_PER_M << "cm, " << mm_tot % MM_PER_CM << "mm";
}