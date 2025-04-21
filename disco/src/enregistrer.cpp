#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

#include "enregistrer.hpp"
#include "noms.hpp"

bool le_fichier_existe_true(std::string const& nom_du_fichier)
{
    std::ifstream fichier{nom_du_fichier} ;

    if (fichier)
        { return true ; }
    return false ;
}

bool enregistrer(std::string const& commande_de_ligne, Discographie& donnees_du_disque)
{
    bool retour{false} ;
    std::istringstream flux{commande_de_ligne} ;
    std::string commande{""} ;
    std::string nom_du_fichier{""} ;
    
    flux >> commande ;
    std::getline(flux, nom_du_fichier) ;
    supprimer_espace_avant_et_apres_d_une_chaine(nom_du_fichier) ;
    
    if ("" == nom_du_fichier)
    {
        std::cout << MARGE << "ERREUR : " << "Veuillez spécifier un nom de fichier!" << std::endl ;
        goto QUIT ;
    }
    
    if (0 == std::size(donnees_du_disque))
    {
        std::cout << MARGE << "ERREUR : " << "Aucune données à enregistrer!" << std::endl ;
        goto QUIT ;
    }

    if (!nom_du_fichier_est_correcte_true(nom_du_fichier))
    {
        std::cerr << MARGE << "ERREUR : " << "Un nom de fichier ne peut pas contenir les caractères suivants : " << CAR_INTERDITS << std::endl ;
        goto QUIT ;
    }
    retour = enregistrer_fichier_si_existe_ou_pas(nom_du_fichier, donnees_du_disque) ;
QUIT :
    return retour ;
}

bool enregistrer_fichier_si_existe_ou_pas(std::string nom_du_fichier, Discographie& donnees_du_disque)
{
    bool retour{true} ;
    std::string choix{""} ;

    if (!le_fichier_existe_true(nom_du_fichier))
    {
        std::cout << MARGE << "Les données seront enregistrées dans un nouveau fichier du nom : <<" << nom_du_fichier <<">>." << std::endl ;
        std::cout << MARGE << "Voullez-vous continuer ([OUI/NON], [O/N], [oui/non], [o/n]) ?" << std::endl ;
        choix = faire_un_choix_oui_non_ou_o_n() ;
        if (("oui" == choix )|| ("o" == choix))
        {
            enreg(nom_du_fichier, donnees_du_disque) ;
        }
        else
        {
            std::cout << MARGE << "Données non sauvegardées!" << std::endl ;
            retour = false ;
        }
    }
    else
    {
        enreg(nom_du_fichier, donnees_du_disque) ;
    }
    return retour ;
}


std::string faire_un_choix_oui_non_ou_o_n(void)
{
    std::string choix{""} ;

    while (true)
    {
        if (obtenir_une_commande_de_ligne_a_la_console(choix))
        {
            choix = transformer_chaine_en_minuscule(choix) ;
            if (("oui" == choix) || ("non" == choix) || ("o" == choix) || ("n" == choix))
                { break ; }
            else
                { std::cout << MARGE << "Entrée invalide!" << std::endl ; }
        }
    }
    return choix ;
}

std::string transformer_chaine_en_minuscule(std::string const& chaine)
{
    std::string ch{""} ;

    for (auto car : chaine)
    {
        if (std::find(std::begin(VALIDE_CARS), std::end(VALIDE_CARS), car) == std::end(VALIDE_CARS))
        {
            using namespace std::literals ;
            return ""s ;
        }
        ch += static_cast<char>(std::tolower(car)) ;
    }
    return ch ;
}


void enreg(std::string const& nom_du_fichier, Discographie& donnees_du_disque)
{
    std::ofstream fichier{nom_du_fichier, std::ios::app} ;

    if(!fichier)
    {
        std::cerr << MARGE << "ERREUR : Echec d'ouverture du fichier <<" << nom_du_fichier << ">>." << std::endl ;
        return ;
    }

    for (auto dn : donnees_du_disque)
        { fichier << dn ; }

    std::cout << MARGE << "Données enregistrées avec succès!" << std::endl ;
    donnees_du_disque.clear() ;
    fichier.close() ;
}