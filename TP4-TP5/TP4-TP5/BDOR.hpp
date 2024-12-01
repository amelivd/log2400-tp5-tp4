#pragma once

#include "CompositeBDOR.hpp"

class BDOR : public CompositeBDOR {
public:
    BDOR() : CompositeBDOR() {
        std::cout << "Objet BDOR cree!" << std::endl;
    }
    std::string getNom() const override { return "BDOR"; }

    void accepter(Visiteur* visiteur) override {
        visiteur->visiter(this);
    }
};