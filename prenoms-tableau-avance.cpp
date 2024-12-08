#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include "tableau-lecture.hpp"
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
using namespace std;

/**
 * Calcule et affiche :
 * - le nombre total de naissances de garçons et de naissances de filles
 * - l'année qui a eu le plus de naissances (garçons et filles confondus), avec leur nombre
 * - le nombre de naissances en moyenne par an
 * - les nombres de prénoms féminins et masculins différents
 * - le prénom masculin et le prénom féminin le plus populaire
 **/

/**int main() {
    vector<vector<string>> t = litTableau("donnees/liste_des_prenoms.txt", 4);
    vector<int> nb_nai_sex = groupByInt(t, {"M", "F"}, 0, 3);
    cout << "Il y a eu " << nb_nai_sex[0] << " naissance de garçons et " << nb_nai_sex[1] << " naissances de filles" << endl;
    vector<string> annees = distinct(t, 1);
    vector<string> prenoms_m = 
    vector<int> tab_ann_nb = groupByInt(t, annees, 1, 3);
    cout << "L'année qui a eu le plus de naissance est : " << annees[indiceMax(tab_ann_nb)] << " avec " << tab_ann_nb[indiceMax(tab_ann_nb)] << " naissances" << endl;
    cout << "En moyenne, naissent " << moyenne(tab_ann_nb) << " enfanst par an" << endl;
    cout << 
    return 0;
}**/

int main() {
    vector<vector<string>> data = litTableau("donnees/liste_des_prenoms.txt", 4);

    vector<string> annees = distinct(data, 1); 
    vector<string> prenomsFilles = distinct(selectLignes(data, 0, "F"), 2);  
    vector<string> prenomsGarcons = distinct(selectLignes(data, 0, "M"), 2); 

    vector<int> t1 = groupByInt(data, annees, 1, 3);

    vector<int> t2Filles = groupByInt(data, prenomsFilles, 2, 3);  
    vector<int> t2Garcons = groupByInt(data, prenomsGarcons, 2, 3);
    cout << nb_nai_sex.size() << endl;

    cout << "Le nombre total de naissances de garçons est de " << somme(t2Garcons) << endl;
    cout << "Le nombre total de naissances de filles est de " << somme(t2Filles) << endl;

    int m1 = indiceMax(t1);  
    cout << "L'année ayant le plus de naissances est " << annees[m1] << " avec " << t1[m1] << " naissances" << endl;
    
    cout << "La moyenne de naissances par an est de " << moyenne(t1) << endl;

    cout << "Le nombre de prénoms féminins distincts est de " << t2Filles.size() << endl;
    cout << "Le nombre de prénoms masculins distincts est de " << t2Garcons.size() << endl;

    int maxPopularitéFilles = indiceMax(t2Filles); 
    cout << "Le prénom féminin le plus populaire est " << prenomsFilles[maxPopularitéFilles] << " avec " << t2Filles[maxPopularitéFilles] << " naissances" << endl;

    int maxPopularitéGarcons = indiceMax(t2Garcons); 
    cout << "Le prénom masculin le plus populaire est " << prenomsGarcons[maxPopularitéGarcons] << " avec " << t2Garcons[maxPopularitéGarcons] << " naissances" << endl;

    return 0;
}


