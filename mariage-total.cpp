-#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
#include<vector>
using namespace std;

/** Calcule et affiche le nombre de mariages totaux entre 2010 et 2022 **/
int main() {
    int resultat = 0;
    ifstream flux;
    flux.open("statistiques-des-jours-des-mariages.txt");
    string j; // j = jours
    int a; // a = annee
    int m; // m = marriage(nombre)
    while(flux) {
        flux >> a >> j >> m; 
        resultat += m; 
        if(m == 4585) {
            break;
        }
        }
    cout << resultat;
    flux.close();
    return 0;
}
