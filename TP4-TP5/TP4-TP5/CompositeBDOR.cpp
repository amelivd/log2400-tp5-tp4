#include "CompositeBDOR.hpp"

CompositeBDOR::CompositeBDOR()
    : ComposantBDOR(this), nombreEnfants(0) {
}

CompositeBDOR::CompositeBDOR(CompositeBDOR* parent) : ComposantBDOR(parent), nombreEnfants(0) {
    parent->ajouter(this);
}

CompositeBDOR::~CompositeBDOR() {
    for (int i = 0; i < nombreEnfants; i++) {
        delete enfants[i];
    }
}

void CompositeBDOR::ajouter(ComposantBDOR* composant) {
    enfants.push_back(composant);
    nombreEnfants++;
    composant->setParent(this); // pour s'assurer que le parent est bien le composite
}

ComposantBDOR* CompositeBDOR::enlever(ComposantBDOR* composant) {
    for (int i = 0; i < nombreEnfants; i++) {
        if (enfants[i] == composant) {
            enfants.erase(enfants.begin() + i);
            nombreEnfants--;
            composant->setParent(composant); // s'assurer que le parent n'est plus le composite
            return composant;
        }
    }

    return nullptr;
}

std::vector<ComposantBDOR*> CompositeBDOR::getEnfants() const { return enfants; }

ComposantBDOR* CompositeBDOR::remplacer(ComposantBDOR* composant, ComposantBDOR* nouveauComposant) {
    for (int i = 0; i < nombreEnfants; i++) {
        if (enfants[i] == composant) {
            enfants[i] = nouveauComposant;
            enfants[i]->setParent(this);
            composant->setParent(composant);
            return composant;
        }
    }

    return nullptr;
}

int CompositeBDOR::getNombreEnfants() const { return nombreEnfants; }