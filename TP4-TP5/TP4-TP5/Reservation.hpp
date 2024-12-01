#pragma once

#include "Offre.hpp"
#include "OffreSubscriber.hpp"
#include "CompositeBDP.hpp"


class Reservation : public ComposantBDP, public OffreSubscriber {
public:
    Reservation(CompositeBDP* parent, ComposantBDOR* offre, std::string adresseCourrielVendeur, std::string dateAchat, std::string nomContactVendeur);

    Reservation* clone() override;

    virtual double getPrixCAD() const override;
    virtual double getPrixEURO() const override;
    std::string getNom() const override { return offre->getNom(); }
    ComposantBDOR* getOffre() const { return offre; }

    void accepter(Visiteur* visiteur) override { visiteur->visiter(this); }

    void update(ComposantBDOR* nouvelleOffre) override;
private:
    struct CloneTag {};

    Reservation(Reservation* res, CloneTag);

    std::string adresseCourrielVendeur;
    std::string dateAchat;
    std::string nomContactVendeur;

    ComposantBDOR* offre;
};