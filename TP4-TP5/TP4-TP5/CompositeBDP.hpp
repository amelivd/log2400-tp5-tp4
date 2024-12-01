#pragma once

#include "ComposantBDP.hpp"

class CompositeBDP : public ComposantBDP {
public:
    CompositeBDP(std::string nom);
    CompositeBDP(CompositeBDP* parent, std::string nom);
    virtual ~CompositeBDP();

    virtual ComposantBDP* clone() override = 0;
    virtual double getPrixCAD() const override;
    virtual double getPrixEURO() const override;
    virtual void ajouter(ComposantBDP* composant);
    virtual ComposantBDP* enlever(ComposantBDP* composant);
    virtual ComposantBDP* remplacer(ComposantBDP* composant, ComposantBDP* nouveauComposant);
    virtual int getNombreEnfants() const;
    virtual std::string getNom() const override;
    virtual void setNom(std::string nom);

    virtual std::vector<ComposantBDP*> getEnfants() const;
    virtual void accepter(Visiteur* visiteur) override = 0;
protected:
    std::vector<ComposantBDP*> enfants;
private:
    int nombreEnfants;
    std::string nom;
};