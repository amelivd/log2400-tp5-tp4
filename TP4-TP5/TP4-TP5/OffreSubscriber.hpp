#pragma once

#include "ComposantBDOR.hpp"

class OffreSubscriber {
public:
    OffreSubscriber() = default;
    virtual ~OffreSubscriber() = default;

    virtual void update(ComposantBDOR* nouelleOffre) = 0;
};