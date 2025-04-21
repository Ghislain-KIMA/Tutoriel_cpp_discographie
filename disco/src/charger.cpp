#include "charger.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
// #include <vector>

#include "noms.hpp"



void charger(std::string const& commande_de_ligne, Discographie& donnees_du_fichier)
{
    std::istringstream flux(commande_de_ligne) ;
    std::string commande{""} ;
    std::string nom_du_fichier{""} ;
    std::string ligne{""} ;
    std::tuple<std::string, std::string, std::string> dn{"", "", ""} ; 
    std::ifstream fichier{} ;

    flux >> commande ;
    std::getline(flux, nom_du_fichier) ;
    supprimer_espace_avant_et_apres_d_une_chaine(nom_du_fichier) ;

    if ("" == nom_du_fichier)
    {
        std::cout << MARGE << "Veuillez spécifier un nom de fichier!" << std::endl ;
        goto QUIT ;
    }

    if (fichier_deja_charger_true(nom_du_fichier))
    {
        std::cout << MARGE << "Le fichier <<" << nom_du_fichier << ">> est déjà charger." << std::endl ;
        goto QUIT ;
    }

    if(!le_fichier_existe_true(nom_du_fichier))
    {
        std::cout << MARGE << "Le fichier <<" << nom_du_fichier << ">> est introuvable." << std::endl ;
        goto QUIT ;
    }

    fichier.open(nom_du_fichier) ;
    
    if(!fichier)
    {
        std::cout << "ERREUR : Echec d'ouverture du fichier <<" << nom_du_fichier << ">>." << std::endl ;
        goto QUIT ; 
    }
    
    while(std::getline(fichier, ligne))
    {
        flux = static_cast<std::istringstream>(ligne) ;
        flux >> dn ;
        donnees_du_fichier.push_back(dn) ;
    }
    fichier.close() ;
    sauvegarder_fichier_charger(nom_du_fichier) ;
QUIT :
    return ;
}

void sauvegarder_fichier_charger(std::string& nom_du_fichier)
{
    std::ofstream fichier{FICHIER_CHARGES, std::ios::app} ;
    supprimer_espace_avant_et_apres_d_une_chaine(nom_du_fichier) ;

    if (!fichier)
    {
        std::cout << MARGE << "ERREUR : " << "Echec de la sauvegarde des fichiers chargés." << std::endl ;
        return ;
    }

    fichier << nom_du_fichier << '\n' ;
    fichier.close() ;
}

bool fichier_deja_charger_true(std::string const& nom_du_fichier)
{
    bool retour{false} ;
    std::string ligne{""} ;
    std::ifstream fichier{FICHIER_CHARGES} ;

    if (!fichier)
        { goto QUIT ; }

    while (std::getline(fichier, ligne))
    {
        supprimer_espace_avant_et_apres_d_une_chaine(ligne) ;
        if (ligne == nom_du_fichier)
        {
            retour = true ;
            break ;
        }
    }
    fichier.close() ;
QUIT :
    return retour ;
}

std::istream& operator>>(std::istream& flux, std::tuple<std::string, std::string, std::string>& T)
{
    std::string morceau{""} ;
    std::string album{""} ;
    std::string artiste{""} ;
    std::getline(flux, morceau, '|') ;
    std::getline(flux, album, '|') ;
    std::getline(flux, artiste, '|') ;
    supprimer_espace_avant_et_apres_d_une_chaine(morceau) ;
    supprimer_espace_avant_et_apres_d_une_chaine(album) ;
    supprimer_espace_avant_et_apres_d_une_chaine(artiste) ;

    T = {morceau, album, artiste} ;
    return flux ;
}