#pragma once

#include "ReservationDecorateur.hpp"
#include "Convertisseur.hpp"

class ReservationModification : public ReservationDecorateur {
public:
    ReservationModification(ComposantBDP* res) : ReservationDecorateur(res), devise(Devise::CAD), prix(0) {}

    ReservationModification(ComposantBDP* res, Devise devise, double prix)
        : ReservationModification(res) {
        this->devise = devise;
        this->prix = prix;
    }

    virtual ~ReservationModification() { delete convertisseur; }

    virtual std::string getNom() const override { return nom; }

    virtual double getPrixCAD() const override {
        if (devise == Devise::CAD)
            return prix + res->getPrixCAD();

        convertisseur->setStrategie(new EuroToCad());
        return convertisseur->convertir(prix) + res->getPrixCAD();
    }

    virtual double getPrixEURO() const override {
        if (devise == Devise::EURO)
            return prix + res->getPrixEURO();

        convertisseur->setStrategie(new CadToEuro());
        return convertisseur->convertir(prix) + res->getPrixEURO();
    }

    virtual void annuler() { this->effacer(); }

    virtual ReservationModification* clone() override = 0;
    virtual void accepter(Visiteur* visiteur) override = 0;
protected:
    ReservationModification() {};

    Devise devise;
    double prix;
    std::string nom;
private:
    Convertisseur* convertisseur = new Convertisseur(new EuroToCad());
};