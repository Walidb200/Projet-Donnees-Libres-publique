#include <stdexcept>
/** @file **/
#include <fstream>
#include <sstream>
#include "tableau-donnees.hpp"

void afficheTableau(vector<vector<string>> tableau) {
    for(int i = 0; i <tableau.size(); i++) {
        vector<string> dans_tab = tableau[i];
        cout << " " << endl;
        for(int j = 0; j<dans_tab.size(); j++) {
            cout << dans_tab[j] << " ";
        }
}
}

int moyenne(vector<int> t) {
    int resultat = 0;
    if(t.size() == 0) {
        cout << "Le tableau est vide";
    } else {
        for(int i = 0; i<t.size(); i++) {
            resultat += t[i];
        }
        resultat = resultat/t.size();
    }
    return resultat;
}

int somme(vector<int> t) {
    int resultat = 0;
    for(int i =0; i<t.size(); i++) {
        resultat += t[i];
            }
    return resultat;
}


int indiceMax(vector<int> t) {
    int ind_max = 0;
    int ind = 0;
    if(t.size() == 0) {
        ind_max = -1;
    } else if(t.size() == 1) {
        ind_max = 0;
    } else {
        for(int i = 0; i<t.size(); i++) {
            ind = i;
            if(t[ind_max] <= t[ind]) {
                ind_max = ind;
            }
        }
    }
    return ind_max;
}

vector<string> colonne(vector<vector<string>> t, int j) {
    vector<string> p;
    for(int m = 0; m < t.size(); m++) {
        p.push_back(t[m][j]);
        }
    return p;
}


vector<int> conversionInt(vector<string> t) {
    vector<int> resultat = vector<int>(t.size());
    for(int i =0; i < t.size(); i++) {
        istringstream(t[i]) >> resultat[i];
    }
    return resultat;
}

vector<vector<string>> selectLignes(vector<vector<string>> t, int j, string valeur) {
   vector<vector<string>> resultat;
    for(int i = 0; i<t.size(); i++) {
        if(t[i][j] == valeur) {
            resultat.push_back(t[i]);
        }
    }
    return resultat;
}

