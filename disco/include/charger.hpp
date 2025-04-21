#ifndef CHARGER_HPP
#define CHARGER_HPP

#include <string>
#include <vector>
using Discographie = std::vector<std::tuple<std::string, std::string, std::string>> ;

void charger(std::string const& commande_de_ligne, Discographie& donnees_du_fichier) ;
void sauvegarder_fichier_charger(std::string& nom_du_fichier) ;
extern void supprimer_espace_avant_et_apres_d_une_chaine(std::string& chaine) ;
bool fichier_deja_charger_true(std::string const& nom_du_fichier) ;
std::istream& operator>>(std::istream& flux, std::tuple<std::string, std::string, std::string>& T) ;
extern bool le_fichier_existe_true(std::string const& nom_du_fichier) ;

#endif // CHARGER_HPP