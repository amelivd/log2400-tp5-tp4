#pragma once

#include <ctime>

#include "Offre.hpp"

class Vol : public Offre {
public:
    Vol(Categorie* cat,
        Devise devise,
        std::string nom,
        double prixUnitaire,
        std::string avion,
        std::string classe,
        std::tm arriveePrevue,
        std::tm departPrevu,
        std::string lieuArrivee,
        std::string lieuDepart,
        std::string noVol,
        std::string transporteur,
        bool wifi)
        : Offre(cat, devise, nom, prixUnitaire),
        avion(avion),
        classe(classe),
        arriveePrevue(arriveePrevue),
        departPrevu(departPrevu),
        lieuArrivee(lieuArrivee),
        lieuDepart(lieuDepart),
        noVol(noVol),
        transporteur(transporteur),
        wifi(wifi) {
    }
private:
    std::string avion;
    std::string classe;
    std::tm arriveePrevue;
    std::tm departPrevu;
    std::string lieuArrivee;
    std::string lieuDepart;
    std::string noVol;
    std::string transporteur;
    bool wifi;
};