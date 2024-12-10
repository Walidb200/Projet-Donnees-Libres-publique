#include <stdexcept>
/** @file **/
#include <iostream>
#include <sstream>
#include <string>
#include "tableau-donnees.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;


/** Affiche le genre et l'espece de l'arbre le plus haut de Paris
 * parmi les "arbres remarquables"
 **/





int main() {
    vector<vector<string>> arbres = litTableauCSV("donnees/arbresremarquablesparis.csv");
    vector<int> hauteur = conversionInt(colonne(litTableauCSV("donnees/arbresremarquablesparis.csv"), 8));
    for(int i = 0; i<hauteur.size(); i++) {
        cout << hauteur[i] <<endl;
    }
    double max_hauteur = 0.0;
    vector<string> arbre_plus_haut;
    string libelle_fr;
    string genre;
    string espece;
    for (int i = 0; i < hauteur.size(); i++) {
        int haut = hauteur[i];

        if (haut > max_hauteur) {
            max_hauteur = haut;
            libelle_fr = arbres[i][15];
            genre = arbres[i][11];
            espece = arbres[i][12];
            //arbre_plus_haut = ligne;
        }
    }
    cout << "L'arbre le plus haut de Paris : " << endl;
    cout << "Libellé français : " << libelle_fr << endl;
    cout << "Genre : " << genre  << endl;
    cout << "Espèce : " << espece << endl;
    cout << "Hauteur : " << max_hauteur << "m" << endl;

    return 0;
}
