
#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cerr << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

vector<string> jours = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};


/** Construction du tableau des mariages par années
 * On suppose que le fichier contient sur chaque ligne une année entre 2010 et 2015
 * suivi d'un jour, puis d'un nombre de mariages
 * @param nom_fichier, le nom du fichier de données
 * @return un tableau d'entiers tel que dans chaque
 * case d'indice i, on trouve le nombre total de mariages de l'année 2010+i
 **/
vector<int> litTableauAnnee(string nom_fichier) {
    ifstream fichier;
    fichier.open(nom_fichier);
    int annees = 0;
    int mariage = 0;
    string jours;
    vector<int> an_tab = {2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019, 2020, 2021, 2022};
    vector<int> t(13);
    while(fichier >> annees >> jours >> mariage) {
            for(int j = 0; j<an_tab.size(); j++) {
                if(annees == an_tab[j]) {
                    t[j] = t[j] + mariage;
                }
            }
    }
    return t;
}

//clang++ mariage-complet.cpp -o mariage

/** Test de la fonction litTableauAnnee **/
void testLitTableauAnnee() {
    vector<int> t = litTableauAnnee("donnees/statistiques-des-jours-des-mariages.txt");
    CHECK(t[0] == 9195); // Nombre de mariages en 2010
    CHECK(t[3] == 9443); // Nombre de mariages en 2013
    CHECK(t[5] == 9046); // Nombre de mariages en 2015
    CHECK(t[12] == 8484); // Nombre de mariages en 2022
}

/** Renvoie le numéro du jour correspondant à la chaîne de caractères
 * @param jour une chaine de caractère contenant un jour de la semaine (première lettre en majuscule)
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

/** Construction du tableau des mariages par jour
 * On suppose que le fichier contient sur chaque ligne une année entre 2010 et 2015
 * suivie d'un jour, puis d'un nombre de mariages
 * @param nom_fichier, le nom du fichier de données
 * @return un tableau d'entiers tel que dans chaque
 * case d'indice i, on trouve le nombre total de mariages célébrés le jour i
 **/
vector<int> litTableauJours(string nom_fichier) {
    ifstream flux;
    flux.open(nom_fichier);
    vector<int> t(7);
    int annee = 0;
    int mariage = 0;
    string jour;
    while(flux >> annee >> jour >> mariage) {
            for(int i = 0; i<jours.size(); i++) {
                if(jour == jours[i]) {
                    t[i] = t[i] + mariage;
                    }
    }
    
}
    return t;
}

/** Test de la fonction litTableauJours **/
void testLitTableauJours() {
    vector<int> t = litTableauJours("donnees/statistiques-des-jours-des-mariages.txt");
    CHECK(t[0] == 8211); // Nombre de mariages le lundi
    CHECK(t[3] == 9579); // Nombre de mariages le jeudi
    CHECK(t[6] == 3); // Nombre de mariages le dimanche
}

/** Renvoie la somme d'un tableau d'entiers
 * @param t, un tableau d'entier
 * @return la somme des valeurs du tableau
 **/
int somme(vector<int> t) {
    int resultat = 0;
    for(int i =0; i<t.size(); i++) {
        resultat += t[i];
            }
    return resultat;
}

/** Test de la fonction somme **/
void testSomme() {
    CHECK(somme({1,2,3}) == 6);
    CHECK(somme({}) == 0);
    CHECK(somme({2,2,4,8}) == 16);
}

/** Renvoie la moyenne d'un tableau d'entier
 * @param t, un tableau d'entiers
 * @return la moyenne (entière) des valeurs
 * (on arrondit à l'entier inférieur)
 **/
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

/** Test de la fonction moyenne **/
void testMoyenne() {
    CHECK(moyenne({1,2,3}) == 2);
    CHECK(moyenne({1}) == 1);
    CHECK(moyenne({2,2,4,8}) == 4);
}


/** Renvoie l'indice de la valeur maximale du tableau
 * @param t, un tableau d'entier
 * @return l'indice de la valeur maximale ou -1 si le tableau est vide
 **/
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

void testIndiceMax() {
    CHECK(indiceMax({}) == -1);
    CHECK(indiceMax({1,2,3}) == 2);
    CHECK(indiceMax({1,3,2}) == 1);
    CHECK(indiceMax({1}) == 0);
    CHECK(indiceMax({2,8,4,4}) == 1);
}

/** Lance les fonctions de test puis affiche :
 * - le nombre total de mariages
 * - le nombre moyen de mariages célébrés par an
 * - l'année où l'on a célébré le plus de mariages (et leur nombre)
 * - le jour de la semaine où l'on célèbre le plus de mariages (et leur nombre)
 * - le pourcentage de mariages célébrés un samedi
 **/
int main() {
    litTableauAnnee("donnees/statistiques-des-jours-des-mariages.txt");
    vector<int> mar_ann = litTableauAnnee("donnees/statistiques-des-jours-des-mariages.txt");
    vector<int> mar_jou = litTableauJours("donnees/statistiques-des-jours-des-mariages.txt");
    float mar_tot = somme(mar_ann);
    int mar_moy = moyenne(mar_ann);
    int indmax_ann = indiceMax(mar_ann);
    int indmax_jou = indiceMax(mar_jou);
    string jours_max;
    
    for(int i = 0; i<mar_jou.size(); i++) {
        if(mar_jou[i] == mar_jou[indmax_jou]) {
            jours_max = jours[i];
            break;
        }
    }
    float nb_jm = mar_jou[indmax_jou];
    float pourcent_mar = (nb_jm/mar_tot) * 100;
    cout << "Le nombre total de mariages célébrés entre 2010 et 2022 est de " << mar_tot <<endl;
    cout << "Le nombre de mariages célébrés en moyenne par an est de " << mar_moy << endl;;
    cout << "L'année où l'on a célébré le plus de mariages est " << 2010 + indmax_ann << " avec " << mar_ann[indmax_ann] << " mariages" <<endl;
    cout << "Le jour de la semaine où l'on a célébré le plus de mariage est le " << jours_max << " avec " << mar_jou[indmax_jou] <<endl;
    cout << "Le pourcentage de mariages célébrés le Samedi est de " << pourcent_mar << "%";
    
}


