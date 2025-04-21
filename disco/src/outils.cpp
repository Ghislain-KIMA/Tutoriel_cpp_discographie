#include <algorithm>
#include "outils.hpp"

#include "noms.hpp"

void supprimer_espace_avant_et_apres_d_une_chaine(std::string& chaine)
{
    auto occurrence{std::find_if_not(std::begin(chaine), std::end(chaine), isspace)} ;

    chaine.erase(std::begin(chaine), occurrence) ;
    std::reverse(std::begin(chaine), std::end(chaine)) ;
    occurrence = std::find_if_not(std::begin(chaine), std::end(chaine), isspace) ;
    chaine.erase(std::begin(chaine), occurrence) ;
    std::reverse(std::begin(chaine), std::end(chaine)) ;
}

bool nom_du_fichier_est_correcte_true(std::string const& nom_du_fichier)
{
    for (auto const& car : nom_du_fichier)
    {
        if (std::find(std::begin(CAR_INTERDITS), std::end(CAR_INTERDITS), car) != std::end(CAR_INTERDITS))
            { return false; }
    }
    return true ;
}