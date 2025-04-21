#ifndef ENREGISTRER_HPP
#define ENREGISTRER_HPP

#include <string>
// #include <vector>
#include <vector>
using Discographie = std::vector<std::tuple<std::string, std::string, std::string>> ;

bool le_fichier_existe_true(std::string const& nom_du_fichier) ;
bool enregistrer(std::string const& commande_de_ligne, Discographie& donnees_du_disque) ;
extern void supprimer_espace_avant_et_apres_d_une_chaine(std::string& chaine) ;
bool enregistrer_fichier_si_existe_ou_pas(std::string nom_du_fichier, Discographie& donnees_du_disque) ;
void enreg(std::string const& nom_du_fichier, Discographie& donnees_du_disque) ;
extern std::ostream& operator<<(std::ostream& flux, std::tuple<std::string, std::string, std::string> const& T) ;
std::string faire_un_choix_oui_non_ou_o_n(void) ;
std::string transformer_chaine_en_minuscule(std::string const& chaine) ;
extern bool obtenir_une_commande_de_ligne_a_la_console(std::string& commande_de_ligne) ;
extern bool nom_du_fichier_est_correcte_true(std::string const& nom_du_fichier) ;

#endif // ENREGISTRER_HPP
