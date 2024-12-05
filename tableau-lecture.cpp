#include <stdexcept>
/** @file **/
#include <fstream>
#include <sstream>
#include "tableau-lecture.hpp"


vector<vector<string>> litTableau(string nom_fichier, int nb_colonnes) {
   ifstream flux;
    flux.open(nom_fichier);
    string contenu_f;
    vector<vector<string>>tab2D;
    vector<string> dans_tab2D;
    while(flux) {
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
