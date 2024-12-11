#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;

/** Renvoie l'arrondissement parisien avec le plus de trafic dans ses stations de métro/RER **/
//Pour exercice 13

int main() {
    vector<vector<string>> t = litTableauCSV("donnees/stations-rer.csv", 11);
    vector<vector<string>> ville_P = selectLignes(t, 9, "Paris");
    vector<string> arr_P = distinct(ville_P, 10);
    vector<int> ville_P_nb_s = groupByInt(ville_P, arr_P, 10, 3);
    int max_nb_st_ind = indiceMax(ville_P_nb_s);
    cout << "L'arrondissement avec le plus de trafic dans ses stations de métro / RER en 2021 est le " << arr_P[max_nb_st_ind] << "ème arrondissement" << endl;
    return 0;
}
