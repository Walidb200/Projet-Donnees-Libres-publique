#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;

/** Affiche le nombre d'arbres du genre Platanus, et le nombre d'espèces
 *  différentes pour ce genre Platanus, parmi les "arbres remarquables"
 **/
int main() {
    string fichier_nom = "les_arbres.csv"; 
    int nb_colonnes = 4; 
    vector<vector<string>> arbres = litTableauCSV(fichier_nom, nb_colonnes);
    int compteur_platanus = 0;
    vector<string> especes_platanus;
    for (size_t i = 0; i < arbres.size(); ++i) {
        vector<string>& ligne = arbres[i];
        if (ligne.size() < nb_colonnes) continue;
        if (ligne[2] == "Platanus") {
            compteur_platanus++;
        }
    }
    cout << "Nombre total d'arbres du genre Platanus : " << compteur_platanus << endl;
    cout << "Nombre d'espèces différentes de Platanus : " << especes_platanus.size() << endl;
    vector<string> especes_platanus_vect(especes_platanus.begin(), especes_platanus.end());
    cout << "Espèces différentes de Platanus :\n";
    for (size_t i = 0; i < especes_platanus_vect.size(); ++i) {
        cout << "- " << especes_platanus_vect[i] << endl;
    }

    return 0;
}

