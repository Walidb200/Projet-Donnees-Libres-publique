 /** @file **/
#include <iostream>
#include "tableau-donnees.hpp" /* pour avoir afficheTableau */
#include "tableau-lecture-csv.hpp"
using namespace std;

/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cerr << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

vector<vector<string>> tableauTest = {
    {"3", "M", "2011", "Bubulle", "3"},
    {"4", "F", "2012", "Bichette", "4"},
    {"7", "F", "2011", "Babouche", "7"},
    {"1", "F", "2011", "Ziboulette", "1"}
};

vector<vector<string>> petites_donnees = { { "a0", "b0"}, { "a1", "b1" } };

void testLitTableauCSVAvecColonnes() {
    CHECK( litTableauCSV("donnees/donnees-test.csv", 5) == tableauTest);
    vector<vector<string>> t = litTableauCSV("donnees/liste_des_prenoms.csv", 5);
    CHECK(t.size() == 25465);
    CHECK(t[0][1] == "M");
    CHECK(t[3][3] == "Olivia");
    CHECK(t[5][4] == "71");
}

void testLitTableauCSVSansColonnes() {
    CHECK( litTableauCSV("donnees/donnees-test.csv") == tableauTest);
    vector<vector<string>> t = litTableauCSV("donnees/liste_des_prenoms.csv");
    CHECK(t.size() == 25465);
    CHECK(t[0][1] == "M");
    CHECK(t[3][3] == "Olivia");
    CHECK(t[5][4] == "71");
    t = litTableauCSV("donnees/statistiques-des-jours-des-mariages.csv");
    CHECK(t.size() == 91);
    CHECK(t[0].size() == 3);
    CHECK(t[0][0] == "2012");
    CHECK(t[0][1] == "Mercredi");
    CHECK(t[0][2] == "542.0");
}

int main() {
    cout << "Lecture d'un petit tableau avec litTableauCSV (avec colonnes)" << endl;
    vector<vector<string>> t = litTableauCSV("donnees/donnees-test.csv",5);
    afficheTableau(t);
    cout << "Lancement des tests de litTableauCSVAvecColonnes" << endl;
    testLitTableauCSVAvecColonnes();
    cout << "Lecture d'un petit tableau avec litTableauCSV (sans colonnes)" << endl;
    t = litTableauCSV("donnees/donnees-test.csv");
    afficheTableau(t);
    cout << "Lancement des tests de litTableauCSVSansColonnes" << endl;
    testLitTableauCSVSansColonnes();
}

