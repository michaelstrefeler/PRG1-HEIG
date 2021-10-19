/*
    But: Le problème des 3 portes ou problème de Monty Hall
    Nom du fichier: strefeler_labo13_2.cpp
    Auteur: Michael Strefeler
    Date de création: 19.10.21
*/
#include <iostream>
#include <iomanip>
#include <random>
#include <functional>

using namespace std;

const int NUMBER_OF_RUNS = 1000000;

int main()
{
    
    /*
        Simuler si l'utilisateur garde toujours son choix initial
        Simuler si l'utilisateur change toujours
        Simuler si l'utilisateur choisit aléatoirement le choix initial
    */

    auto gen_int = bind(uniform_int_distribution<int>(1, 3), mt19937(69420));
    int initial_choice, winner;
    int i = 0;
    int wins_initial_choice = 0;
    int wins_different_choice = 0;
    
    while(i < NUMBER_OF_RUNS){
        initial_choice = gen_int();
        winner = gen_int();

        if(initial_choice == winner){
            wins_initial_choice++;
        }else{
            wins_different_choice++;
        }
        i++;
    }
    double percent_keep = double(wins_initial_choice) / i * 100;
    double percent_change = double(wins_different_choice) / i * 100;
    cout << fixed << setprecision(2);
    cout << percent_keep << "\% des gens qui gardent leur choix gagnent et " 
    << percent_change << "\% des gens qui changent leur choix gagnent.";
}