#pragma once

#include "Offre.hpp"

class Hebergement : public Offre {
public:
    Hebergement(Categorie* cat, Devise devise, std::string nom, double prixUnitaire, std::string ville, std::string secteur, double coteSur10)
        : Offre(cat, devise, nom, prixUnitaire), ville(ville), secteur(secteur), coteSur10(coteSur10) {
    }
private:
    std::string ville;
    std::string secteur;
    double coteSur10;
};