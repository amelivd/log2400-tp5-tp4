#include "CompositeBDP.hpp"

CompositeBDP::CompositeBDP(std::string nom) : ComposantBDP(this), nombreEnfants(0), nom(nom) {}

CompositeBDP::CompositeBDP(CompositeBDP* parent, std::string nom) : ComposantBDP(parent), nombreEnfants(0), nom(nom) {
    parent->ajouter(this);
}

CompositeBDP::~CompositeBDP() {
    for (int i = 0; i < nombreEnfants; i++) {
        delete enfants[i];
    }
}

double CompositeBDP::getPrixCAD() const {
    double prix = 0;
    for (const auto& enfant : enfants) {
        prix += enfant->getPrixCAD();
    }
    return prix;
}

double CompositeBDP::getPrixEURO() const {
    double prix = 0;
    for (const auto& enfant : enfants) {
        prix += enfant->getPrixEURO();
    }
    return prix;
}


void CompositeBDP::ajouter(ComposantBDP* composant) {
    enfants.push_back(composant);
    nombreEnfants++;
    composant->setParent(this);
}

ComposantBDP* CompositeBDP::enlever(ComposantBDP* composant) {
    for (int i = 0; i < nombreEnfants; i++) {
        if (enfants[i] == composant) {
            enfants.erase(enfants.begin() + i);
            nombreEnfants--;
            composant->setParent(composant);
            return composant;
        }
    }

    return nullptr;
}

ComposantBDP* CompositeBDP::remplacer(ComposantBDP* composant, ComposantBDP* nouveauComposant) {
    for (int i = 0; i < nombreEnfants; i++) {
        if (enfants[i] == composant) {
            enfants[i] = nouveauComposant;
            nouveauComposant->setParent(this);
            composant->setParent(composant);
            return composant;
        }
    }

    return nullptr;
}

std::vector<ComposantBDP*> CompositeBDP::getEnfants() const {
    return enfants;
}

void CompositeBDP::setNom(std::string nom) { this->nom = nom; }

std::string CompositeBDP::getNom() const { return nom; }

int CompositeBDP::getNombreEnfants() const { return nombreEnfants; }