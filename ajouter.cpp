#include <sstream>
#include <vector>
#include "ajouter.hpp"

void ajouter(std::string const& commande_de_ligne, Discographie& donnees_du_disque)
{
    std::istringstream flux{commande_de_ligne} ;
    std::string commande{""} ;
    std::string morceau{""} ;
    std::string album{""} ;
    std::string artiste{""} ;

    flux >> commande ;

    std::getline(flux, morceau, '|') ;
    std::getline(flux, album, '|') ;
    std::getline(flux, artiste, '|') ;
    supprimer_espace_avant_et_apres_d_une_chaine(morceau) ;
    supprimer_espace_avant_et_apres_d_une_chaine(album) ;
    supprimer_espace_avant_et_apres_d_une_chaine(artiste) ;
    if ("" == morceau) { morceau = "Morceau inconnu" ; }
    if ("" == album) { album = "Album inconnu" ; }
    if ("" == artiste) { artiste = "Artiste inconnu" ; }

    donnees_du_disque.push_back({morceau, album, artiste}) ;
}