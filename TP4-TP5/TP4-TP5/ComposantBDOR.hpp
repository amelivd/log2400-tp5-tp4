#pragma once

#include <iostream>
#include <vector>

#include "Visiteur.hpp"

class ComposantBDOR {
public:
    ComposantBDOR() : parent(this) {}

    ComposantBDOR(ComposantBDOR* parent) : parent(parent) {}

    virtual ~ComposantBDOR() = default;

    ComposantBDOR* getParent() const { return parent; }
    void setParent(ComposantBDOR* parent) { this->parent = parent; }

    virtual double getPrixCAD() const { return -1; };
    virtual double getPrixEURO() const { return -1; };

    virtual void accepter(class Visiteur* visiteur) = 0;
    virtual std::string getNom() const = 0;

protected:
    ComposantBDOR* parent;
};