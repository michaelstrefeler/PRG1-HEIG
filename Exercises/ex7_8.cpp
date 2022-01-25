#include <iostream>

using namespace std;

class C{
    int valeur;
    const int numero;
    static int prochain_numero;
    static int n_objets_vivants;
    public:
    C():valeur(prochain_numero), numero(prochain_numero){
        cout << "Creation objet " << numero << endl;
        ++prochain_numero;
        ++n_objets_vivants;
    }
    C(const C&): C(){};
    ~C(){cout << "Destruction objet " << numero << endl; --n_objets_vivants;}
    C& operator=(const C& objet){
        valeur = objet.valeur;
        cout << "Affectation de l'objet: " << objet.no()
            << " dans l'objet:" << numero << endl;
    }
    int no() const {return numero;}
    static int prochain_no(){return prochain_numero;}
    static int compteur() {return n_objets_vivants;}

    void afficher_etat_C(){
        /*cout << "C a " << C::compteur() << " objet(s) vivant(s); prochain no: "
                << C::prochain_no() << */
    }
};