#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "tableau-donnees.hpp"
#include "tableau-lecture.hpp"
using namespace std;

/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cerr << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

vector<string> annees = {"2010", "2011", "2012", "2013", "2014", "2015", "2016", "2017", "2018", "2019", "2020", "2021", "2022"};
vector<string> jours = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};


/** Construction du tableau des mariages par années à partir d'un
 * tableau de données 2D (de chaines de caractères)
 * Chaque ligne contient : l'année, le jour, puis le nombre de mariages
 * @param t un tableau de données 2D de chaines de caractère
 * @return un tableau d'entiers tel que dans chaque
 * case d'indice i, on trouve le nombre total de mariages de l'année 2010+i
 **/
vector<int> creeTableauAnnee(vector<vector<string>> data) {
    vector<int> t;
    //int m = 0;
    for(int i = 0; i<annees.size(); i++) {
       int resultn = somme(conversionInt(colonne(selectLignes(data, 0, annees[i]), 2)));
       t.push_back(resultn); 
    }
        //resultat.push_back(m);
        //par = {};
        //m = 0;
    /**for(int i = 0; i<t.size(); i++) {
        cout << t[i] << endl;
    }**/
    return t;
}

/** Test de la fonction CreeTableauAnnee **/
void testCreeTableauAnnee() {
    vector<vector<string>> data = litTableau("donnees/statistiques-des-jours-des-mariages.txt", 3);
    vector<int> t = creeTableauAnnee(data);
    CHECK(t[0] == 9195); // Nombre de mariages en 2010
    CHECK(t[3] == 9443); // Nombre de mariages en 2013
    CHECK(t[5] == 9046); // Nombre de mariages en 2015
    CHECK(t[12] == 8484); // Nombre de mariages en 2022
}

/** Renvoie le numéro du jour correspondant à la chaîne de caractères
 * @param jour une chaine de caractères contenant un jour de la semaine (première lettre en majuscule)
 * @return un numéro entre 0 et 6 correspondant au jour de la semaine ou
 * -1 si le jour n'est pas valide
 **/
int indiceJour(string jour) {
    for(int i=0; i < jours.size(); i++) {
        if (jour == jours[i]) {
            return i;
        }
    }
    return -1;
}

void testIndiceJour() {
    CHECK(indiceJour("Lundi") == 0);
    CHECK(indiceJour("Samedi") == 5);
    CHECK(indiceJour("Dimanche") == 6);
    CHECK(indiceJour("samedi") == -1);
}

/** Construction du tableau des mariages à partir d'un
 * tableau de données 2D (de chaines de caractères)
 * suivi d'un jour, puis d'un nombre de mariages
 * Chaque ligne contient : l'année, le jour, puis le nombre de mariages
 * @param t un tableau de données 2D de chaines de caractère
 * @return un tableau d'entiers tel que dans chaque
 * case d'indice i, on trouve le nombre total de mariages célébrés le jour i
 **/
vector<int> creeTableauJours(vector<vector<string>> data) {
    vector<int> t;
    //int m = 0;
    for(int i = 0; i<jours.size(); i++) {
       int resultn = somme(conversionInt(colonne(selectLignes(data, 1, jours[i]), 2)));
       t.push_back(resultn); 
    }
        //resultat.push_back(m);
        //par = {};
        //m = 0;
    /**for(int i = 0; i<t.size(); i++) {
        cout << t[i] << endl;
    }**/
    return t;
}

/** Test de la fonction litTableauJours **/
void testCreeTableauJours() {
    vector<vector<string>> data = litTableau("donnees/statistiques-des-jours-des-mariages.txt", 3);
    vector<int> t = creeTableauJours(data);
    CHECK(t[0] == 8211); // Nombre de mariages le lundi
    CHECK(t[3] == 9579); // Nombre de mariages le jeudi
    CHECK(t[6] == 3); // Nombre de mariages le dimanche
}


/** Lance les fonctions de test puis affiche :
 * - le nombre total de mariages
 * - le nombre moyen de mariages célébrés par an
 * - l'année où l'on a célébré le plus de mariages (et leur nombre)
 * - le jour de la semaine où l'on célèbre le plus de mariages (et leur nombre)
 * - le pourcentage de mariages célébrés un samedi
 **/
int main() {
    testCreeTableauAnnee();
    testCreeTableauJours();
    vector<vector<string>> data = litTableau("donnees/statistiques-des-jours-des-mariages.txt", 3);
    vector<int> t_ann = creeTableauAnnee(data);
    vector<int> mar_jou = creeTableauJours(data);
    int ann_marmax = 0;
    string jours_max;
    for(int i = 0; i<t_ann.size(); i++) {
        ann_marmax = 2010 + i;
        if(t_ann[i] == indiceMax(t_ann)) {
            break;
    }
    }
    for(int i = 0; i<mar_jou.size(); i++) {
        if(mar_jou[i] == indiceMax(mar_jou)) {
            jours_max = jours[i];
            break;
        }
    }
    float nb_jm = indiceMax(mar_jou);
    float pourcent_mar = (nb_jm/somme(t_ann)) * 100;
    cout << "Le nombre total de mariage entre 2010 et 2022 est de " << somme(t_ann) << " mariages" << endl;
    cout << "Le nombre moyen de mariage par an est de " << moyenne(t_ann) << " mariages par an" << endl;
    cout << "L'année ou l'on a célébrée le plus de mariage est " << ann_marmax << endl;
    cout << "Le jour de la semaine où l'on a célébré le plus de mariage est le " << jours_max << " avec " << indiceMax(mar_jou) << " mariages" << endl;
    cout << "Le pourcentage de mariages célébrés le samedi est de " << pourcent_mar << "%";
}

