/*
    But: Dire combien de temps ça prendra pour doubler son avoir bancaire
    Nom du fichier: strefeler_labo12_1.cpp
    Auteur: Michael Strefeler
    Date de création: 13.10.21
*/
#include <iostream>

using namespace std;

int main()
{
    double yearly_interest, start_balance;
    int year = 0;

    cout << "Donnez moi un montant et le taux annuel en %: ";
    cin >> start_balance >> yearly_interest;

    double balance = start_balance;
    double target_balance = 2.0 * start_balance;

    while (balance < target_balance)
    {
        ++year;
        double interest = balance * yearly_interest / 100.0;
        balance = balance + interest;
    }

    cout << "L'investissement double apres " << year << " annees." << endl;
}