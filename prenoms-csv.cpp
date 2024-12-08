#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/** Calcule et affiche le prénom le plus donné une année donnée
 * ainsi que le nombre de naissance cette année là **/
int main() {
    ifstream flux;
    flux.open("liste_des_prenoms.csv");
    string ligne;
    char s;
    int a;
    string p, pmax;
    int n;
    int resultat, maxn;
    int a_propose;
    cout << "Entrez une année entre 2006 et 2021 : ";
    cin >> a_propose;
    while(getline(flux,ligne)) {
        flux >> s >> a >> p >> n;
        if(a_propose == a) {
            resultat += n;
            if(maxn < n) {
                maxn = n;
                pmax = p;
            }
        }
    }
    cout << "En " << a_propose << ", il y a eu " << resultat << " naissances" <<endl;
    cout << "Le prénom le plus donné a été : " << pmax << " (donnée " << maxn << " fois)" <<endl;
    flux.close();
    return 0;
}

