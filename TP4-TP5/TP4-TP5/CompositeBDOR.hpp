#pragma once

#include "ComposantBDOR.hpp"

class CompositeBDOR : public ComposantBDOR {
public:
    CompositeBDOR();
    CompositeBDOR(CompositeBDOR* parent);

    virtual ~CompositeBDOR();

    virtual void ajouter(ComposantBDOR* composant);
    virtual ComposantBDOR* enlever(ComposantBDOR* composant);
    virtual int getNombreEnfants() const;
    virtual ComposantBDOR* remplacer(ComposantBDOR* composant, ComposantBDOR* nouveauComposant);
    virtual std::string getNom() const override = 0;

    virtual void accepter(class Visiteur* visiteur) override = 0;

    virtual std::vector<ComposantBDOR*> getEnfants() const;
protected:
    std::vector<ComposantBDOR*> enfants;

private:
    int nombreEnfants;
};

