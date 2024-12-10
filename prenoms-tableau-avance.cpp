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


int main() {
    vector<vector<string>> data = litTableau("donnees/liste_des_prenoms.txt", 4);

    vector<string> annees = distinct(data, 1); 
    vector<vector<string>> sex_m = selectLignes(data, 0, "M");
    vector<vector<string>> sex_f = selectLignes(data, 0, "F");
    vector<string> prenomsGarcons = distinct(sex_m, 2); 
    vector<string> prenomsFilles = distinct(sex_f, 2);  

    vector<int> t1 = groupByInt(data, annees, 1, 3);

    vector<int> t2Filles = groupByInt(sex_f, prenomsFilles, 2, 3);  
    vector<int> t2Garcons = groupByInt(sex_m, prenomsGarcons, 2, 3);

    cout << "Le nombre total de naissances de garçons est de " << somme(t2Garcons) << endl;
    cout << "Le nombre total de naissances de filles est de " << somme(t2Filles) << endl;

    int m1 = indiceMax(t1);  
    cout << "L'année ayant le plus de naissances est " << annees[m1] << " avec " << t1[m1] << " naissances" << endl;
    
    cout << "La moyenne des naissances par an est de " << moyenne(t1) << endl;

    cout << "Le nombre de prénoms féminins distincts est de " << t2Filles.size() << endl;
    cout << "Le nombre de prénoms masculins distincts est de " << t2Garcons.size() << endl;

    int maxPopularitéFilles = indiceMax(t2Filles); 
    cout << "Le prénom féminin le plus populaire est " << prenomsFilles[maxPopularitéFilles] << " avec " << t2Filles[maxPopularitéFilles] << " naissances" << endl;

    int maxPopularitéGarcons = indiceMax(t2Garcons); 
    cout << "Le prénom masculin le plus populaire est " << prenomsGarcons[maxPopularitéGarcons] << " avec " << t2Garcons[maxPopularitéGarcons] << " naissances" << endl;

    return 0;
}
