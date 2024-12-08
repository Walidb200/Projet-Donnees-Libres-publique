#include <stdexcept>
/** @file **/
#include <fstream>
#include <sstream>
#include "tableau-donnees-avance.hpp"


int chercheIndice(vector<string> t, string valeur) {
    for (size_t i = 0; i < t.size(); ++i) {
        if (t[i] == valeur) {
            return i;
        }
    }
    return -1;
}

vector<string> distinct(vector<vector<string>> data, int j) {
    vector<string> resultat;
    for (const auto& ligne : data) {
        if (chercheIndice(resultat, ligne[j]) == -1) {
            resultat.push_back(ligne[j]);
        }
    }
    return resultat;
}

vector<double> conversionDouble(vector<string> t) {
    vector<double> vec_res;//(t.size());
    for(int i = 0; i<t.size(); i++) {
        double res = 0;
        stringstream ss;
        ss << t[i];
        ss >> res;
        vec_res.push_back(res);
    }
    if (vec_res.size() == 0) {
        throw invalid_argument("Conversion échouée");
    }
    return vec_res;
}

vector<int> groupByInt(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    vector<int> resultat(valeurs.size());
    for (int i = 0; i <valeurs.size(); i++) {
        string valeur_s = valeurs[i];
        for (int j = 0; j<data.size(); j++) {
            if(data[j][j1] == valeur_s) {
                stringstream ss;
                ss << data[j][j2];
                int res;
                ss >> res;
                resultat[i] += res;
            
        }
    }
    }
    return resultat;
}

vector<double> groupByDouble(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    vector<double> resultat(valeursDistinctes.size(), 0.0);
    for (const auto& ligne : data) {
        string valeurj1 = ligne[j1];
        double valeurj2 = conversionDouble(ligne[j2]);
        int index = chercheIndice(valeurs, valeurj1);
        if (index != -1) {
            resultat[index] += valeurj2;
        }
    }
    return resultat;
}

// Force l'instanciation des templates




