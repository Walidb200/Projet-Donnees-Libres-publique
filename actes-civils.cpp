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
    vector<vector<string>> t = litTableauCSV("donnees/actes-civils.csv", 4);
    vector<string> annees_nai = distinct(selectLignes(t, 0, "Naissances"), 1);
    vector<int> naissances_nb = groupByInt(selectLignes(t, 0, "Naissances"), annees_nai, 1, 3);
    int max_nai_ind = indiceMax(naissances_nb);
    cout << "L'année avec le plus de naissances est " << annees_nai[max_nai_ind] << " avec " << naissances_nb[max_nai_ind] << " naissances" << endl;
    vector<string> annee_mar = distinct(selectLignes(t, 0, "Mariages"), 1);
    vector<int> mar_nb = groupByInt(selectLignes(t, 0, "Mariages"), annee_mar, 1, 3);
    int max_mar_ind = indiceMax(mar_nb);
    cout << "L'année avec le plus de mariages est " << annees_nai[max_mar_ind] << " avec " << naissances_nb[max_mar_ind] << " mariages" << endl;
    return 0;
    
}
