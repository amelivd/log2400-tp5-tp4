#pragma once

#include "CompositeBDP.hpp"

class Segment : public CompositeBDP {
public:
    Segment(CompositeBDP* parent, std::string nom) : CompositeBDP(parent, nom) {
        std::cout << "  Segment " + this->getNom() + " cree dans le " << parent->getNom() << std::endl;
    }

    Segment* clone() override {
        Segment* clone = new Segment(this->getNom(), CloneTag{});
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

    Segment(std::string nom, CloneTag) : CompositeBDP(nom) {}
};