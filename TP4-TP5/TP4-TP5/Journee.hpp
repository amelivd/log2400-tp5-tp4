#pragma once

#include "CompositeBDP.hpp"

class Journee : public CompositeBDP {
public:
    Journee(CompositeBDP* parent, std::string nom) : CompositeBDP(parent, nom) {
        std::cout << "    Journee " << nom << " creee dans le segment " << parent->getNom() << "!" << std::endl;
    }

    Journee* clone() override {
        Journee* clone = new Journee(this->getNom(), CloneTag{});
        for (ComposantBDP* enfant : this->enfants) {
            clone->ajouter(enfant->clone());
        }
        return clone;
    }

    void accepter(Visiteur* visiteur) override {
        visiteur->visiter(this);
    }
private:
    struct CloneTag {};

    Journee(std::string nom, CloneTag) : CompositeBDP(nom) {}
};