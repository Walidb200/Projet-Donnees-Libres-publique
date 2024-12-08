#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-lecture.hpp"
using namespace std;


/**
 * Demande à l'utilisateur un prénom et calcule
 * - le nombre de garçons et filles à qui l'on a donné ce prénom
 * - la meilleure année pour ce prénom pour les garçons et filles
 **/
int main() {
    int naiss_tot = 0;
    string choix_pren;
    int resultat_m = 0;
    int resultat_f = 0;
    vector<vector<string>> t = litTableau("donnees/liste_des_prenoms.txt", 4);
    vector<string> naiss_tab = colonne(t, 3);
    naiss_tot = somme(conversionInt(naiss_tab));
    cout << "Nombre total de naissances : " << naiss_tot << endl;
    cout << "Choisissez un prénom : ";
    cin >> choix_pren;
    vector<int> an_naiss_tab = conversionInt(colonne(selectLignes(t, 2, choix_pren), 1));
    vector<int> an_naiss_tab_m = {};
    vector<int> an_naiss_tab_f = {};
    vector<vector<string>> pren_tab = selectLignes(t, 2, choix_pren);
    vector<int> pren_tab_nb = conversionInt(colonne(selectLignes(t, 2, choix_pren), 3));
    vector<int> pren_tab_nb_m = {};
    vector<int> pren_tab_nb_f = {};
    vector<string> sex = colonne(selectLignes(t, 2, choix_pren), 0);
    for(int i = 0; i < pren_tab_nb.size(); i++) {
        if(sex[i] == "M") {
            pren_tab_nb_m.push_back(pren_tab_nb[i]);
        } else {
            pren_tab_nb_f.push_back(pren_tab_nb[i]);
                }
    }
    for(int i = 0; i < an_naiss_tab.size(); i++) {
        if(sex[i] == "M") {
            an_naiss_tab_m.push_back(an_naiss_tab[i]);
        } else {
            an_naiss_tab_f.push_back(an_naiss_tab[i]);
                }
    }
    int nmax_m = indiceMax(pren_tab_nb_m);
    int nmax_f = indiceMax(pren_tab_nb_f);
    resultat_m = somme(pren_tab_nb_m);
    resultat_f = somme(pren_tab_nb_f);
    if(resultat_m == 0) {
        cout << "Le prénom " << choix_pren << " n'a été donné à aucun garçon entre 2004 et 2023"<<endl;
         cout <<  "Le prénom " << choix_pren << " a été donné " << resultat_f << " filles entre 2004 et 2023" <<endl;
        cout << "L'année la plus forte est " << an_naiss_tab_f[nmax_f] << " avec " << pren_tab_nb_f[nmax_f] << " enfants" << endl;
    }else if(resultat_f == 0) {
        cout << "Le prénom " << choix_pren << " a été donné " << resultat_m << " garçons entre 2004 et 2023"<< endl;
         cout << "L'année la plus forte est " << an_naiss_tab_m[nmax_m] << " avec " << pren_tab_nb_m[nmax_m] << " enfants" << endl;
        cout << "Le prénom " << choix_pren << " n'a été donné à aucune fille entre 2004 et 2023" << endl;
    } else {
    cout << "Le prénom " << choix_pren << " a été donné " << resultat_m << " garçons entre 2004 et 2023"<< endl;
    cout << "L'année la plus forte est " << an_naiss_tab_m[nmax_m] << " avec " << pren_tab_nb_m[nmax_m] << " enfants"<<endl;
    cout <<  "Le prénom " << choix_pren << " a été donné " << resultat_f << " filles entre 2004 et 2023" <<endl;
     cout << "L'année la plus forte est " << an_naiss_tab_f[nmax_f] << " avec " << pren_tab_nb_f[nmax_f] << " enfants" << endl;
    }
    
    return 0;
}
