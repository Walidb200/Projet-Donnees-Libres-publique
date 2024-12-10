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
    vector<vector<string>> arbres = litTableauCSV("donnees/arbresremarquablesparis.csv");
    vector<vector<string>> arbres_platanus = selectLignes(arbres, 11, "Platanus");
    vector<string> arbres_platanus_nb = colonne(arbres_platanus, 11);
    int compteur_platanus = 0;
    int compt_platanus_esp = 0;
    vector<string> arbres_platanus_esp = distinct(arbres_platanus, 12);
    for (int i = 0; i < arbres_platanus_nb.size(); ++i) {
        compteur_platanus++;
    }
    for(int i = 0; i < arbres_platanus_esp.size(); i++) {
        compt_platanus_esp++;
    }
    cout << "Nombre total d'arbres du genre Platanus : " << compteur_platanus << endl;
    cout << "Nombre d'espèces différentes de Platanus : " << compt_platanus_esp << endl;

    return 0;
}
