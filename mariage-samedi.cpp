#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/** Calcule et affiche le nombre de mariages un samedi entre 2010 et 2022 **/
int main() {
    int resultat = 0;
    ifstream flux;
    flux.open("statistiques-des-jours-des-mariages.txt");
    string j;
    int a;
    int m;
    while(flux >> a >> j >> m) {
        if(j == "Samedi" ) {
            resultat += m;
         }
    }
    cout << resultat;
    flux.close();
    return 0;
}
