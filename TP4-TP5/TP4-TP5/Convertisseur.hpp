#pragma once

#include "Devise.hpp"
#include "TauxCadEuro.hpp"


class StrategieConversion {
public:
    virtual ~StrategieConversion() = default;
    virtual double convertir(double montant) = 0;
};

class EuroToCad : public StrategieConversion {
public:
    double convertir(double montant) override {
        return montant * TauxCadEuro::getInstance().getTaux();
    }
};

class CadToEuro : public StrategieConversion {
public:
    double convertir(double montant) override {
        return montant / TauxCadEuro::getInstance().getTaux();
    }
};

class Convertisseur {
public:
    Convertisseur(StrategieConversion* strategie) : strategie(strategie) {}

    double convertir(double montant) {
        return strategie->convertir(montant);
    }

    void setStrategie(StrategieConversion* strategie) {
        delete this->strategie;
        this->strategie = strategie;
    }

private:
    StrategieConversion* strategie;
};


