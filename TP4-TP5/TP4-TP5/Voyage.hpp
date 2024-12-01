#pragma once

#include "CompositeBDP.hpp"

class Voyage : public CompositeBDP {
public:
    Voyage(std::string proprio) : CompositeBDP(getNomDuVoyage(proprio)) {
        std::cout << this->getNom() << " cree!" << std::endl;
    }

    Voyage* clone() override {
        Voyage* clone = new Voyage(this->getNom(), CloneTag{});
        for (ComposantBDP* enfant : this->enfants) {
            clone->ajouter(enfant->clone());
        }
        return clone;
    }

    // Methode pour creer un clone du voyage avec un nouveau proprietaire
    Voyage* copie(std::string nouveauProprio) {
        Voyage* clone = this->clone();
        clone->setNom(nouveauProprio);

        std::cout << clone->getNom() << " copie a partir du " << this->getNom() << "!" << std::endl;
        return clone;
    }

    virtual void enleverSegment(std::string nom) {
        ComposantBDP* segment = nullptr;
        for (ComposantBDP* enfant : this->enfants) {
            if (enfant->getNom() == nom) {
                segment = enfant;
                break;
            }
        }

        if (segment != nullptr) {
            std::cout << "  Segment " << segment->getNom() << " efface!" << std::endl;
            this->enlever(segment);
            delete segment;
        }
    }

    virtual void setNom(std::string nom) override { CompositeBDP::setNom(getNomDuVoyage(nom)); }

    void accepter(Visiteur* visiteur) override {
        visiteur->visiter(this);
    }
private:
    struct CloneTag {};

    // Constructeur prive pour la methode clone qui permet de creer un clone sans afficher le message de creation
    Voyage(std::string nom, CloneTag) : CompositeBDP(nom) {}

    // Methode pour determiner le nom du voyage en fonction du proprietaire
    std::string getNomDuVoyage(std::string proprio) {
        char premiereLettre = std::tolower(proprio[0]);
        if (premiereLettre == 'a' || premiereLettre == 'e' || premiereLettre == 'i' || premiereLettre == 'o' || premiereLettre == 'u') {
            return "Voyage d'" + proprio;
        }
        else {
            return "Voyage de " + proprio;
        }
    }
};