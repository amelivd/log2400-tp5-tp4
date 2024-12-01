#pragma once

#include "OffreDecorateur.hpp"

class RabaisOffre : public OffreDecorateur {
public:
    RabaisOffre(ComposantBDOR* offre, double rabais) : OffreDecorateur(offre), rabais(rabais) {}

    virtual double getPrixCAD() const override {
        return offre->getPrixCAD() - rabais;
    }

    virtual double getPrixEURO() const override {
        return offre->getPrixEURO() - rabais;
    }

    virtual void accepter(Visiteur* v) override {
        v->visiter(this);
    }
private:
    double rabais;
};