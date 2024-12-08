/** @file **/
#include <vector>
#include <string>
using namespace std;

/** Construction d'un tableau 2D de chaînes lu depuis un fichier CSV
 * @param fichier le nom d'un fichier contenant un nombre fixe
  * de valeurs par ligne, séparées par des espaces
 * @param nb_colonnes le nombre de colonnes du fichier
 * @return un tableau de chaînes de caractères à deux dimensions
 **/
vector<vector<string>> litTableauCSV(string fichier, int nb_colonnes);

/** Construction d'un tableau 2D de chaînes lu depuis un fichier CSV
 * @param fichier le nom d'un fichier contenant un nombre fixe
  * de valeurs par ligne, séparés par des espaces
 * @return un tableau de chaînes de caractères à deux dimensions
 **/
vector<vector<string>> litTableauCSV(string fichier);



