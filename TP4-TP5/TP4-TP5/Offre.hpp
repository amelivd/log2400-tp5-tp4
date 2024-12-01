#pragma once

#include "Devise.hpp"
#include "Convertisseur.hpp"
#include "OffrePublisher.hpp"
#include "Categorie.hpp"

class Offre : public ComposantBDOR, public OffrePublisher {
public:

    Offre(Categorie* cat, Devise devise, std::string nom, double prixUnitaire)
        : ComposantBDOR(cat), devise(devise), nom(nom), prixUnitaire(prixUnitaire) {
        cat->ajouter(this);
        std::cout << "Entree " << nom << " rattachee a la categorie " << cat->getNom() << " creee!" << std::endl;
    }
    virtual ~Offre() { delete convertisseur; }

    virtual double getPrixCAD() const override {
        if (devise == Devise::CAD)
            return prixUnitaire;

        convertisseur->setStrategie(new EuroToCad());
        return convertisseur->convertir(prixUnitaire);
    }

    virtual double getPrixEURO() const override {
        if (devise == Devise::EURO)
            return prixUnitaire;

        convertisseur->setStrategie(new CadToEuro());
        return convertisseur->convertir(prixUnitaire);
    }

    virtual void accepter(class Visiteur* visiteur) override { visiteur->visiter(this); }

    virtual void setPrixUnitaire(double prixUnitaire) { this->prixUnitaire = prixUnitaire; }
    virtual std::string getNom() const override { return nom; }
    virtual double getPrixUnitaire() const { return prixUnitaire; }
    virtual Devise getDevise() const { return devise; }
protected:
    Devise devise;
    std::string nom;
    double prixUnitaire;
private:
    Convertisseur* convertisseur = new Convertisseur(new EuroToCad());
};
