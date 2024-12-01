#pragma once

#include "Categorie.hpp"
#include "Vol.hpp"

class CategorieTransport : public Categorie {
public:
    CategorieTransport(CompositeBDOR* parent) : Categorie(parent, "Transport") {}
};
