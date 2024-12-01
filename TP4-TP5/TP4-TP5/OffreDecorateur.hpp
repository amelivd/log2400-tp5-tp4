#pragma once

#include "CompositeBDOR.hpp"
#include "OffrePublisher.hpp"

class OffreDecorateur : public ComposantBDOR, public OffrePublisher {
public:
    OffreDecorateur(ComposantBDOR* offre) : ComposantBDOR(offre->getParent()), offre(offre) {
        dynamic_cast<CompositeBDOR*>(offre->getParent())->remplacer(offre, this);
        offre->setParent(this);

        if (auto castedOffre = dynamic_cast<OffreDecorateur*>(offre)) {
            castedOffre->notifierDecoration(this);
        }
        else if (auto castedOffre = dynamic_cast<Offre*>(offre)) {
            castedOffre->notifierDecoration(this);
        }
    }

    virtual void effacer() {
        ComposantBDOR* child = offre;
        ComposantBDOR* parent = this->getParent();

        if (auto parentComposite = dynamic_cast<CompositeBDOR*>(parent)) {
            parentComposite->remplacer(this, child);
            this->notifierDecoration(child);
            delete this;
        }
        else {
            dynamic_cast<OffreDecorateur*>(parent)->setOffre(child);
            child->setParent(parent);
            delete this;
        }
    }

    virtual double getPrixCAD() const override {
        return offre->getPrixCAD();
    }

    virtual double getPrixEURO() const override {
        return offre->getPrixEURO();
    }

    virtual void setOffre(ComposantBDOR* offre) {
        this->offre = offre;
        offre->setParent(this);
    }

    virtual ComposantBDOR* getOffre() const { return offre; }

    virtual void accepter(Visiteur* v) override = 0;

    virtual ~OffreDecorateur() = default;

    virtual std::string getNom() const override { return offre->getNom(); }
protected:
    ComposantBDOR* offre;
};