#ifndef AFFICHER_HPP
#define AFFICHER_HPP

// #include <string>
#include <vector>

using Discographie = std::vector<std::tuple<std::string, std::string, std::string>> ;

inline std::ostream& operator<<(std::ostream& flux, std::tuple<std::string, std::string, std::string> const& T) ;
extern void supprimer_espace_avant_et_apres_d_une_chaine(std::string& chaine) ;
void afficher(std::string const& commande_de_ligne, Discographie donnees) ;
void afficher_morceaux(Discographie& donnees) ;
void afficher_albums(Discographie& donnees) ;
void afficher_artristes(Discographie& donnees) ;
Discographie operator+(Discographie const& G, Discographie const& D) ;

#endif 