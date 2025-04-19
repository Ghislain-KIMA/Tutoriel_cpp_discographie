#include <vector>
#include <iostream>
#include "quitter.hpp"

#include "noms.hpp"

void quitter(Discographie& donnees_du_disque)
{
    std::string choix{""} ;

    if (0 == std::size(donnees_du_disque))
        { goto QUIT ; }

    std::cout << MARGE << "Il existe des données non sauvegardées. Voullez-vous les sauvegarder ([OUI/NON], [O/N], [oui/non], [o/n]) ?" << std::endl ;
    choix = faire_un_choix_oui_non_ou_o_n() ;

    while(true)
    {
        if (("oui" == choix) || ("o" == choix))
        {
            /* renvoi true si les données ont été enregistrées. */
            if (enregistrer(donnees_du_disque))
                { break ; }
            else
            {
                std::cout << MARGE << "Voullez-vous sauvegarder les données ([OUI/NON], [O/N], [oui/non], [o/n]) ?" << std::endl ;
                choix = faire_un_choix_oui_non_ou_o_n() ;
            }
        }
        else
        {
            std::cout << MARGE << "Données non sauvegardées!" << std::endl ;
            donnees_du_disque.clear() ;
            break ;
        }
    }
QUIT :
    std::remove(FICHIER_CHARGES) ;
}

bool enregistrer(Discographie& donnees_du_disque)
{
    std::string nom_du_fichier{""} ;

    std::cout << MARGE << "Veuillez entrez le nom du fichier." << std::endl ;
    entrer_un_nom_de_fichier_valide(nom_du_fichier) ;
    return enregistrer_fichier_si_existe_ou_pas(nom_du_fichier, donnees_du_disque) ;
}


void entrer_un_nom_de_fichier_valide(std::string& nom_du_fichier)
{
    nom_du_fichier = "" ;

    while("" == nom_du_fichier)
    {
        obtenir_une_commande_de_ligne_a_la_console(nom_du_fichier) ;
        supprimer_espace_avant_et_apres_d_une_chaine(nom_du_fichier) ;

        if ("" == nom_du_fichier)
            { std::cout << MARGE << "ERREUR : " << "Nom du fichier invalide!" << std::endl ; }
           
        if (!nom_du_fichier_est_correcte_true(nom_du_fichier))
        {
            std::cout << MARGE << "ERREUR : " << "Un nom de fichier ne peut pas contenir les caractères suivants : " << CAR_INTERDITS << std::endl ;
            nom_du_fichier = "" ;
        }
    }
}