#pragma once

class TauxCadEuro {
public:

    ~TauxCadEuro() = default;
    double getTaux() const { return this->taux; }
    void setTaux(double taux) { this->taux = taux; }

    static TauxCadEuro& getInstance() {
        static TauxCadEuro instance;
        return instance;
    }

private:
    TauxCadEuro() = default;

    double taux{ 1.5 };
};
