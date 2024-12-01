#pragma once

#include "Offre.hpp"

class Excursion : public Offre {
public:
    Excursion(Categorie* cat, Devise devise, std::string nom, double prixUnitaire, std::string ville, int nbEtoiles)
        : Offre(cat, devise, nom, prixUnitaire), ville(ville), nbEtoiles(nbEtoiles) {
    }
private:
    std::string ville;
    int nbEtoiles;
};