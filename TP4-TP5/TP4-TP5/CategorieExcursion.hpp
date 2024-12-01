#pragma once

#include "Categorie.hpp"
#include "Excursion.hpp"

class CategorieExcursion : public Categorie {
public:
    CategorieExcursion(CompositeBDOR* parent) : Categorie(parent, "Excursion") {}
};