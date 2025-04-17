#include <iostream>
#include <limits>
#include <sstream>
#include <vector>
#include "menu.hpp"

#include "names.hpp"

using Discographie = std::vector<std::tuple<std::string, std::string, std::string>> ;

/**
 * @brief Fonction permettant de lire une chaine ce caractère à la console.
 * @details Pas assez de details explicite.
 * @param[in,out] commande_de_ligne est la référence d'une chaine de caractère.
 * @note voici un exemple d'utilisation.
 * @code
 * st::cout << "Bonjour tout le monde." << std::endl ;
 * @endcode
 *
 */

bool obtenir_une_commande_de_ligne_a_la_console(std::string& commande_de_ligne)
{
    std::cout << "> " ;

    if (!std::getline(std::cin, commande_de_ligne))
    {
        if (std::cin.eof())
        {
            std::cerr << MARGE << "ERREUR : Flux fermeé!" << std::endl ;
            std::cin.clear() ;
        }
        if (std::cin.fail())
        {
            std::cerr << MARGE << "ERREUR : Entrée invalide!" << std::endl ;
            std::cin.clear() ;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n') ;
        }
        return false ;
    }
    return true ;
}


ListeCmds commande_de_commande_de_ligne_en_ListeCmds(std::string const& commande_de_ligne, std::unordered_map<std::string, ListeCmds> const& commandes_disponibles) /*-- COOL --*/
{
    ListeCmds retour{ListeCmds::DEFAULT} ;
    std::string commande{""} ;
    std::istringstream flux(commande_de_ligne) ;

    if ("" == commande_de_ligne)
        { goto QUIT ; }

    flux >> commande ;
    commande = transformer_chaine_en_minuscule(commande) ;

    for (auto const& cmd : commandes_disponibles)
    {
        if(cmd.first == commande)
        {
            retour = cmd.second ;
            goto QUIT ;
        }
    }
    std::cout << MARGE << "Erreur : la commande <<" << commande << ">> est invalide." << std::endl ;
QUIT :
    return retour ;
}


bool executer_commande(ListeCmds const choix, std::string const& commande_de_ligne, Discographie& donnees_du_disque, Discographie& donnees_du_fichier)
{
    bool retour{true} ;

    switch (choix)
    {
        case ListeCmds::AJOUTER :
            ajouter(commande_de_ligne, donnees_du_disque) ;
            break ;
        case ListeCmds::AFFICHER :
            afficher(commande_de_ligne, donnees_du_disque+donnees_du_fichier) ;
            break ;
        case ListeCmds::ENREGISTRER :
            enregistrer(commande_de_ligne, donnees_du_disque) ;
            break ;
        case ListeCmds::CHARGER :
            charger(commande_de_ligne, donnees_du_fichier) ;
            break ;
        case ListeCmds::QUITTER :
            quitter(donnees_du_disque) ;
            std::cout << MARGE << "Merci d'avoir utiliser notre application." << std::endl ;
            retour = false ;
            break ;
        default :
            break ;
    }
    return retour ;
}