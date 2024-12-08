#include <stdexcept>
/** @file **/
#include <iostream>
#include <fstream>
#include <sstream>
#include "tableau-lecture-csv.hpp"


vector<vector<string>> litTableauCSV(string nom_fichier, int nb_colonnes) {
    ifstream flux;
    flux.open(nom_fichier);
    string contenu_f;
    vector<vector<string>>tab2D;
    vector<string> dans_tab2D;
    string ligne;
    while(getline(flux,ligne)) {
        for(int i = 0; i < nb_colonnes; i++) {
            flux >> contenu_f;
            if(flux) {
                dans_tab2D.push_back(contenu_f);
            }
        }
    tab2D.push_back(dans_tab2D);
    dans_tab2D = {};
    }
    tab2D.pop_back();
    flux.close();
    return tab2D;
}

vector<vector<string>> litTableauCSV(string nom_fichier) {
    ifstream flux(nom_fichier);
    string ligne;
    vector<vector<string>> tab2D; 
    while (getline(flux, ligne)) {
        stringstream ss(ligne);
        string contenu_f;
        vector<string> dans_tab2D; 
        while (getline(ss, contenu_f, ',')) { 
            dans_tab2D.push_back(contenu_f);
        }
        if (!dans_tab2D.empty()) {
            tab2D.push_back(dans_tab2D);
        }
    }

    flux.close();
    return tab2D;
}




