#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <fstream>

#include "menu.hpp"
#include "noms.hpp"

using Discographie = std::vector<std::tuple<std::string, std::string, std::string>> ;

int main(void)
{
    bool boucle{true} ;
    ListeCmds choix{0} ;
    std::string commande_de_ligne{""} ;
    std::unordered_map<std::string, ListeCmds> commandes_disponibles{{"ajouter", ListeCmds::AJOUTER},
                                                                     {"afficher", ListeCmds::AFFICHER},
                                                                     {"enregistrer", ListeCmds::ENREGISTRER},
                                                                     {"charger", ListeCmds::CHARGER},
                                                                     {"quitter", ListeCmds::QUITTER}} ;
    Discographie donnees_du_disque{} ;
    Discographie donnees_du_fichier{} ;

    while(boucle)
    {
        if (obtenir_une_commande_de_ligne_a_la_console(commande_de_ligne))
        {
            choix = commande_de_commande_de_ligne_en_ListeCmds(commande_de_ligne, commandes_disponibles) ;
            boucle = executer_commande(choix, commande_de_ligne, donnees_du_disque, donnees_du_fichier) ;
        }
        else
            { std::cout << MARGE << "ERREUR : Echec de lecture de commande." << std::endl ; }
    }
    return 0 ;
}
