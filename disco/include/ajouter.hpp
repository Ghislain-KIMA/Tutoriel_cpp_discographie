#ifndef AJOUTER_HPP
#define AJOUTER_HPP

// #include <string>
using Discographie = std::vector<std::tuple<std::string, std::string, std::string>> ;

void ajouter(std::string const& commande_de_ligne, Discographie& donnees_du_disque) ;
extern void supprimer_espace_avant_et_apres_d_une_chaine(std::string& chaine) ;

#endif // AJOUTER_HPP