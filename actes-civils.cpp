#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;

/** Affiche l'année avec le plus de naissances et l'année avec le plus de mariages
 **/
int main() {
    string fichier_nom = "actes_civils.csv"; 
    int nb_colonnes = 5; 
    vector<vector<string>> actes = litTableauCSV(fichier_nom, nb_colonnes);
    int annee_min = 9999, annee_max = 0;
    for (int i = 0; i < actes.size(); i++) {
        vector<string>& ligne = actes[i];
        if (ligne.size() >= nb_colonnes) {
            int annee = stoi(ligne[0]);
            if (annee < annee_min) annee_min = annee;
            if (annee > annee_max) annee_max = annee;
        }
    }
    int nb_annees = annee_max - annee_min + 1;
    vector<int> naissances_par_annee(nb_annees, 0);
    vector<int> mariages_par_annee(nb_annees, 0);
    for (int i = 0; i < actes.size(); ++i) {
         vector<string>& ligne = actes[i];
        if (ligne.size() >= nb_colonnes) {
            int annee = stoi(ligne[0]);
            int naissances = stoi(ligne[2]);
            int mariages = stoi(ligne[3]);
            int index = annee - annee_min; 
            naissances_par_annee[index] += naissances;
            mariages_par_annee[index] += mariages;
        }
    }
    int max_naissances = 0;
    int annee_max_naissances = annee_min;
    for (int i = 0; i < nb_annees; ++i) {
        if (naissances_par_annee[i] > max_naissances) {
            max_naissances = naissances_par_annee[i];
            annee_max_naissances = annee_min + i;
        }
    }
    int max_mariages = 0;
    int annee_max_mariages = annee_min;
    for (int i = 0; i < nb_annees; ++i) {
        if (mariages_par_annee[i] > max_mariages) {
            max_mariages = mariages_par_annee[i];
            annee_max_mariages = annee_min + i;
        }
    }
    cout << "Année avec le plus de déclarations de naissances : " 
         << annee_max_naissances << " (" << max_naissances << " naissances)" << endl;
    cout << "Année avec le plus de déclarations de mariages : " 
         << annee_max_mariages << " (" << max_mariages << " mariages)" << endl;

    return 0;
}

