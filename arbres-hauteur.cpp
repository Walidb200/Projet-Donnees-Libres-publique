#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;

/** Affiche le genre et l'espece de l'arbre le plus haut de Paris
 * parmi les "arbres remarquables"
 **/


int main() {
    string fichier_nom = "arbres_remarquables.csv"; 
    int nb_colonnes = 4; 
    vector<vector<string>> arbres = litTableauCSV(fichier_nom, nb_colonnes);
    double max_hauteur = 0.0;
    vector<string> arbre_plus_haut;

    for (size_t i = 0; i < arbres.size(); i++) {
        vector<string>& ligne = arbres[i];
        double hauteur = stod(ligne[3]); 

        if (hauteur > max_hauteur) {
            max_hauteur = hauteur;
            arbre_plus_haut = ligne;
        }
    }
    cout << "L'arbre le plus haut de Paris :\n";
    cout << "Nom français : " << arbre_plus_haut[0] << "\n";
    cout << "Genre : " << arbre_plus_haut[1] << "\n";
    cout << "Espèce : " << arbre_plus_haut[2] << "\n";
    cout << "Hauteur : " << max_hauteur << " m\n";

    return 0;
}

