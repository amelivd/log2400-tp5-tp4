#pragma once

#include "Categorie.hpp"
#include "Hebergement.hpp"

class CategorieHebergement : public Categorie {
public:
    CategorieHebergement(CompositeBDOR* parent) : Categorie(parent, "Hebergement") {}
};