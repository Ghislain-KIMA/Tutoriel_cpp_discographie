#include <iostream>
#include <sstream>
#include "afficher.hpp"
#include <algorithm>

#include "noms.hpp"

inline std::ostream& operator<<(std::ostream& flux, std::tuple<std::string, std::string, std::string> const& T)
{
    auto [morceau, album, artiste] = T ;
    supprimer_espace_avant_et_apres_d_une_chaine(morceau) ;
    supprimer_espace_avant_et_apres_d_une_chaine(album) ;
    supprimer_espace_avant_et_apres_d_une_chaine(artiste) ;

    flux << morceau << " | " << album << " | " << artiste << "\n" ;
    return flux ;
}

void afficher(std::string const& commande_de_ligne, Discographie donnees) /*-- COOL --*/
{
    std::string commande{""} ;
    std::string type_affichage{""} ;
    std::istringstream flux{commande_de_ligne} ;

    flux >> commande ;
    flux >> type_affichage ;
    supprimer_espace_avant_et_apres_d_une_chaine(type_affichage) ;

    if ("" == type_affichage)
    {
        std::cout << MARGE << "ERREUR : Veuillez spécifier le type d'affichage." << std::endl ;
        return ;
    }

    if ("morceaux" == type_affichage)
        { afficher_morceaux(donnees) ; }
    else if ("albums" == type_affichage)
        { afficher_albums(donnees) ; }
    else if ("artistes" == type_affichage)
        { afficher_artristes(donnees) ; }
    else
        { std::cout << MARGE << "Erreur : Commande invalide." << std::endl ; }
}

void afficher_morceaux(Discographie& donnees)
{
    if (0 == std::size(donnees))
    {
        std::cout << MARGE << "Erreur : Aucune données à afficher." << std::endl ;
        return ;
    }

    std::sort(std::begin(donnees), std::end(donnees)) ;

    for (auto const& dn : donnees)
        { std::cout << PUCE_0 << dn ; }
}

void afficher_albums(Discographie& donnees)
{
    std::vector<std::string> albums{} ;

    if (0 == std::size(donnees))
    {
        std::cout << MARGE << "Erreur : Aucune données à afficher." << std::endl ;
        return ;
    }

    for (auto dn : donnees)
    {
        if (std::find(std::begin(albums), std::end(albums), std::get<ALBUM>(dn)) == std::end(albums))
            { albums.push_back(std::get<ALBUM>(dn)) ; }
    }

    std::sort(std::begin(albums), std::end(albums)) ;
    std::sort(std::begin(donnees), std::end(donnees)) ;

    for (auto al : albums)
    {
        for (auto dn : donnees)
        {
            if (al == std::get<ALBUM>(dn))
            {
                std::cout << PUCE_0 << al << " | " << std::get<ARTISTE>(dn) << std::endl ;
                break ;
            }
        }
        for (auto dn : donnees)
        {
            if (al == std::get<ALBUM>(dn))
            {
                std::cout << ESPACE_PUCE_1 << PUCE_1 << std::get<MORCEAU>(dn) << std::endl ;
            }
        }
    }
}

void afficher_artristes(Discographie& donnees)
{
    std::vector<std::string> artistes{} ;
    std::vector<std::string> albums{} ;

    if (0 == std::size(donnees))
    {
        std::cout << MARGE << "Erreur : Aucune données à afficher." << std::endl ;
        return ;
    }

    std::sort(std::begin(donnees), std::end(donnees)) ;

    for (auto& dn : donnees)
    {
        if (std::find(std::begin(artistes), std::end(artistes), std::get<ARTISTE>(dn)) == std::end(artistes))
            { artistes.push_back(std::get<ARTISTE>(dn)) ; }
    }

    std::sort(std::begin(artistes), std::end(artistes)) ;

    for (auto const& art : artistes)
    {
        for (auto const& dn : donnees)
        {
            if (art == std::get<ARTISTE>(dn))
            {
                if (std::find(std::begin(albums), std::end(albums), std::get<ALBUM>(dn)) == std::end(albums))
                    { albums.push_back(std::get<ALBUM>(dn)) ; }
            }
        }

        std::cout << PUCE_0 << art << std::endl ;
        for (auto const& al : albums)
        {
            std::cout << ESPACE_PUCE_1 << PUCE_1 << al <<  std::endl ;
            for (auto const& dn : donnees)
            {
                if ((al == std::get<ALBUM>(dn)) && (art == std::get<ARTISTE>(dn)))
                {
                    std::cout << ESPACE_PUCE_1 << ESPACE_PUCE_1 << PUCE_1 << std::get<MORCEAU>(dn) << std::endl ;
                }
            }
        }
        albums.clear() ;
    }
}

Discographie operator+(Discographie const& G, Discographie const& D)
{
    Discographie donnees{} ;
    for(auto g : G)
        { donnees.push_back(g) ; }
    for(auto d : D)
        { donnees.push_back(d) ; }
    return donnees ;
}