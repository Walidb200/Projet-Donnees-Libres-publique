#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cerr << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

vector<vector<string>> tableauTest = {
    { "M", "2011", "Bubulle", "3"},
    { "F", "2012", "Bichette", "4"},
    { "F", "2011", "Babouche", "7"},
    { "F", "2011", "Ziboulette", "1"} 
};

/** Affiche le contenu d'un tableau de chaînes à deux dimensions
 * @param tableau un tableau à deux dimensions
 **/
void afficheTableau(vector<vector<string>> tableau) {
    for(int i = 0; i <tableau.size(); i++) {
        vector<string> dans_tab = tableau[i];
        cout << " " << endl;
        for(int j = 0; j<dans_tab.size(); j++) {
            cout << dans_tab[j] << " ";
        }
}
}

void testAfficheTableau() {
    afficheTableau(tableauTest);
}


/** Construction d'un tableau 2D de chaines de caractères lu depuis un fichier
 * @param fichier le nom d'un fichier contenant un nombre fixe
  * de colonnes séparées par des espaces
 * @param nb_colonnes le nombre de colonnes du fichier
 * @return un tableau de chaines de caractères à deux dimensions
 **/
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

/** Test de la fonction litTableau **/
void testLitTableau() {
    CHECK(litTableau("donnees/donnees-test.txt", 4) == tableauTest);
    vector<vector<string>> m = litTableau("donnees/donnees-test.txt", 4);
    CHECK(m[0][0] == "M");
    vector<vector<string>> t = litTableau("donnees/liste_des_prenoms.txt", 4);
    CHECK(t.size() == 25465);
    CHECK(t[0][0] == "M");
    CHECK(t[3][2] == "Olivia");
    CHECK(t[5][3] == "71");
    
}

/** Extraction d'une colonne d'un tableau de données
 * @param t un tableau 2D de chaines de caractères
 * @param i un numéro de colonne
 * @return la colonne j, représentée par un vecteur de chaines de caractères
 **/
vector<string> colonne(vector<vector<string>> t, int i) {
    vector<string> j;
    for(int p = 0; p < t.size(); p++) {
        j.push_back(t[p][i]);
        }
    return j;
}

/** Test de la fonction colonne **/
void testColonne() {
    CHECK(colonne(tableauTest, 0) == vector<string>({"M","F","F","F"}));
    CHECK(colonne(tableauTest, 1) == vector<string>({"2011","2012","2011","2011"}));
    CHECK(colonne(tableauTest, 2) == vector<string>({"Bubulle","Bichette","Babouche","Ziboulette"}));
    CHECK(colonne(tableauTest, 3) == vector<string>({"3","4","7","1"}));
}

/** Convertit un tableau de chaines de caractères en un tableau d'entiers
 * @param t, un vecteur de chaines de caractères
 * @return un vecteur d'entiers
 **/
vector<int> conversionInt(vector<string> t) {
    vector<int> resultat = vector<int>(t.size());
    for(int i =0; i < t.size(); i++) {
        istringstream(t[i]) >> resultat[i];
    }
    return resultat;
}

void testConversionInt() {
    CHECK(conversionInt({}) == vector<int>({}));
    CHECK(conversionInt({"1","2","3"}) == vector<int>({1,2,3}));
}

/** copier la fonction somme déjà écrite **/
int somme(vector<int> t) {
    int resultat = 0;
    for(int i =0; i<t.size(); i++) {
        resultat += t[i];
            }
    return resultat;
}

void testSomme() {
    CHECK(somme({1,1,1}) == 3);
    CHECK(somme({}) == 0);
    CHECK(somme({20,20,20}) == 60);
}

/** copier la fonction moyenne déjà écrite **/
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

void testMoyenne() {
    CHECK(moyenne({1,2,3}) == 2);
    CHECK(moyenne({1}) == 1);
    CHECK(moyenne({2,2,4,8}) == 4);
}

/** copier la fonction indiceMax déjà écrite **/
int indiceMax(vector<int> t) {
    int ind_max = 0;
    int ind = 0;
    if(t.size() == 0) {
        ind_max = -1;
    } else if(t.size() == 1) {
        ind_max = t[0];
    } else {
        for(int i = 0; i<t.size(); i++) {
            ind = t[i];
            if(ind_max < ind) {
                ind_max = ind;
            }
        }
    }
    return ind_max;
}

void testIndiceMax() {
    CHECK(indiceMax({}) == -1);
    CHECK(indiceMax({1,2,3}) == 3);
    CHECK(indiceMax({1,3,2}) == 3);
    CHECK(indiceMax({1}) == 1);
    CHECK(indiceMax({2,8,4,4}) == 8);
}

/** Sélection des lignes d'un tableau de données
 * Sélectionne un ensemble de lignes en fonction d'un critère donné
 * @param t, un tableau contenant des lignes de données
 * @param j, l'indice de la colonne à vérifier
 * @param valeur, une chaine de caractères correspondant au critère
 * @return un tableau de données ne contenant que les lignes de t telles
 *  que la colonne j ait la valeur correspondant au critère
 **/
vector<vector<string>> selectLignes(vector<vector<string>> t, int j, string valeur) {
    vector<vector<string>> resultat;
    for(int i = 0; i<t.size(); i++) {
        if(t[i][j] == valeur) {
            resultat.push_back(t[i]);
        }
    }
    //afficheTableau(resultat);
    return resultat;
}

/** Test de la fonction selectLignes **/
void testSelectLignes() {
    CHECK(selectLignes(tableauTest, 0, "M") == vector<vector<string>>({{ "M", "2011", "Bubulle", "3"}}));
    CHECK(selectLignes(tableauTest, 1, "2011") == vector<vector<string>>({{ "M", "2011", "Bubulle", "3"}, { "F", "2011", "Babouche", "7"}, { "F", "2011", "Ziboulette", "1"}}));
    CHECK(selectLignes(tableauTest, 1, "2012") == vector<vector<string>>({{ "F", "2012", "Bichette", "4"}}));
}

/** Lance les tests de litTableau, selectLignes et colonne puis
 * affiche le nombre total de naissances puis
 * demande à l'utilisateur un prénom et calcule et affiche
 * - le nombre de garçons et filles à qui l'on a donné ce prénom
 * - la meilleure année pour ce prénom pour les garçons et filles
 **/
int main() {
    testLitTableau();
    testSelectLignes();
    testColonne();
    int naiss_tot = 0;
    string choix_pren;
    int resultat_m, anmax_m = 0;
    int resultat_f, anmax_f = 0;
    vector<vector<string>> t = litTableau("donnees/liste_des_prenoms.txt", 4);
    vector<string> naiss_tab = colonne(t, 3);
    naiss_tot = somme(conversionInt(naiss_tab));
    cout << "Nombre total de naissances : " << naiss_tot << endl;
    cout << "Choisissez un prénom : ";
    cin >> choix_pren;
    //vector<vector<string>> an_naiss = selectLignes(t, 2, choix_pren);
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
    int m = 0;
    int f = 0;
    for(int i = 0; i < pren_tab_nb.size(); i++) {
        if (resultat_f == 0) {
            m = pren_tab_nb_m[i];
        } else if(resultat_f != 0 && resultat_m != 0) {
            m = pren_tab_nb_m[i];
            f = pren_tab_nb_f[i];
        } else if(resultat_m == 0) {
            f = pren_tab_nb_f[i];
        }
        if(nmax_m == m) {
            anmax_m = an_naiss_tab_m[i];
        } else if(nmax_f == f) {
            anmax_f = an_naiss_tab_f[i];
        
    }
    }
    if(resultat_m == 0) {
        cout << "Le prénom " << choix_pren << " n'a été donné à aucun garçon entre 2004 et 2023"<<endl;
         cout <<  "Le prénom " << choix_pren << " a été donné " << resultat_f << " filles entre 2004 et 2023" <<endl;
        cout << "L'année la plus forte est " << anmax_f << " avec " << nmax_f << " enfants" << endl;
    }else if(resultat_f == 0) {
        cout << "Le prénom " << choix_pren << " a été donné " << resultat_m << " garçons entre 2004 et 2023"<< endl;
         cout << "L'année la plus forte est " << anmax_m << " avec " << nmax_m << " enfants" << endl;
        cout << "Le prénom " << choix_pren << " n'a été donné à aucune fille entre 2004 et 2023" << endl;
    } else {
    cout << "Le prénom " << choix_pren << " a été donné " << resultat_m << " garçons entre 2004 et 2023"<< endl;
    cout << "L'année la plus forte est " << anmax_m << " avec " << nmax_m << " enfants"<<endl;
    cout <<  "Le prénom " << choix_pren << " a été donné " << resultat_f << " filles entre 2004 et 2023" <<endl;
     cout << "L'année la plus forte est " << anmax_f << " avec " << nmax_f << " enfants" << endl;
    }
    
    return 0;
}

