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
    stringstream ss(t);
    double resultat;
    ss >> resultat;
    if (ss.fail()) {
        throw invalid_argument("Conversion échouée: " + t);
    }
    return resultat;
}

vector<int> groupByInt(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    vector<int> resultat(valeurs.size(), 0);
    for (const auto& ligne : data) {
        string valeurj1 = ligne[j1];
        int valeurj2 = stoi(ligne[j2]);
        int index = chercheIndice(valeurs, j1);
        if (index != -1) {
            resultat[index] += j2;
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




