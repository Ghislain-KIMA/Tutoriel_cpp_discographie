#ifndef MENU_HPP
#define MENU_HPP 

#include <string>
#include <unordered_map>
// #include "ajouter.hpp"

using Discographie = std::vector<std::tuple<std::string, std::string, std::string>> ;

enum class ListeCmds
{
    DEFAULT,
    AJOUTER,
    AFFICHER,
    ENREGISTRER,
    CHARGER,
    QUITTER
} ;

bool obtenir_une_commande_de_ligne_a_la_console(std::string& commande_de_ligne) ;
ListeCmds commande_de_commande_de_ligne_en_ListeCmds(std::string const& commande_de_ligne, std::unordered_map<std::string, ListeCmds> const& commandes_disponibles) ;
bool executer_commande(ListeCmds const choix, std::string const& commande_de_ligne, Discographie& donnees_du_disque, Discographie& donnees_du_fichier) ;
extern void ajouter(std::string const& commande_de_ligne, Discographie& donnees_du_disque) ;
extern void afficher(std::string const& commande_de_ligne, Discographie donnees) ;
extern bool enregistrer(std::string const& commande_de_ligne, Discographie& donnees_du_disque) ;
extern void charger(std::string const& commande_de_ligne, Discographie& donnees_du_fichier) ;
extern void quitter(Discographie& donnees_du_disque) ;
extern std::string transformer_chaine_en_minuscule(std::string const& chaine) ;
extern Discographie operator+(Discographie const& G, Discographie const& D) ;

#endif // MENU_HPP