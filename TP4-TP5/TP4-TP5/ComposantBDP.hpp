#pragma once

#include <iostream>
#include <vector>

#include "Visiteur.hpp"

class ComposantBDP {
public:
    ComposantBDP() : parent(this) {}
    ComposantBDP(ComposantBDP* parent) : parent(parent) {}
    virtual ~ComposantBDP() = default;

    virtual ComposantBDP* clone() = 0;
    virtual double getPrixCAD() const = 0;
    virtual double getPrixEURO() const = 0;
    virtual std::string getNom() const = 0;

    ComposantBDP* getParent() const { return parent; }
    void setParent(ComposantBDP* parent) { this->parent = parent; }

    virtual void accepter(Visiteur* visiteur) = 0;
protected:
    ComposantBDP* parent;
};