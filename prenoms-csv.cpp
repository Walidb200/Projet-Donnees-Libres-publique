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
    ifstream flux("donnees/liste_des_prenoms.csv");
    string ligne;
    getline(flux, ligne);
    string nombre1;
    string MF;
    string annee;
    string prenoms;
    string nombre2;
    int resultat = 0;
    int nombre;
    int a_propose = 0;
    int maxn = 0;
    string pmax = "";
    int annee_int;
    cout << "Entrez une année entre 2006 et 2021 : ";
    cin >> a_propose;
    while(flux) {
        getline(flux, nombre1, ';');
        getline(flux, MF, ';');
        getline(flux, annee, ';');
        getline(flux, prenoms, ';');
        getline(flux, nombre2);
        istringstream(nombre2) >> nombre;
        stringstream(annee) >> annee_int;
        if(a_propose == annee_int) {
            resultat += nombre;
            if(maxn < nombre) {
                maxn = nombre;
                pmax = prenoms;
            }
        }
    }
    cout << "En " << a_propose << ", il y a eu " << resultat << " naissances" <<endl;
    cout << "Le prénom le plus donné a été : " << pmax << " (donnée " << maxn << " fois)" <<endl;
    flux.close();
    return 0;
}
