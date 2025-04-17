#ifndef QUITTER_HPP
#define QUITTER_HPP

using Discographie = std::vector<std::tuple<std::string, std::string, std::string>> ;

void quitter(Discographie& donnees_du_disque) ;
bool enregistrer(Discographie& donnees_du_disque) ;
void entrer_un_nom_de_fichier_valide(std::string& nom_du_fichier) ;
extern bool nom_du_fichier_est_correcte_true(std::string const& nom_du_fichier) ;
extern void supprimer_espace_avant_et_apres_d_une_chaine(std::string& chaine) ;
extern std::string faire_un_choix_oui_non_ou_o_n(void) ;
extern bool enregistrer_fichier_si_existe_ou_pas(std::string nom_du_fichier, Discographie& donnees_du_disque) ;
extern bool obtenir_une_commande_de_ligne_a_la_console(std::string& commande_de_ligne) ;

#endif // QUITTER_HPP