#pragma once

#include "CompositeBDOR.hpp"

class Categorie : public CompositeBDOR {
public:
    Categorie(CompositeBDOR* parent, std::string nom) : CompositeBDOR(parent), nom(nom) {
        std::cout << "Categorie " << nom << " creee!" << std::endl;
    }
    virtual ~Categorie() = default;
    virtual ComposantBDOR* getOffre(std::string nom) const {
        for (ComposantBDOR* enfant : enfants) {
            if (enfant->getNom() == nom)
                return enfant;
        }

        return nullptr;
    }

    virtual void accepter(Visiteur* visiteur) override {
        visiteur->visiter(this);
    }

    virtual std::string getNom() const override { return nom; }
private:
    std::string nom;
};
