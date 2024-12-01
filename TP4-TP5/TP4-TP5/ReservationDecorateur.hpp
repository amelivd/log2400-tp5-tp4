#pragma once

#include "CompositeBDP.hpp"
#include "Visiteur.hpp"

class ReservationDecorateur : public ComposantBDP {
public:
    ReservationDecorateur(ComposantBDP* res) : ComposantBDP(res->getParent()), res(res) {
        dynamic_cast<CompositeBDP*>(res->getParent())->remplacer(res, this);
        res->setParent(this);
    }
    ReservationDecorateur() : ComposantBDP(), res(nullptr) {}

    virtual ~ReservationDecorateur() = default;

    virtual ReservationDecorateur* clone() override = 0;

    virtual double getPrixCAD() const override {
        return res->getPrixCAD();
    }

    virtual double getPrixEURO() const override {
        return res->getPrixEURO();
    }

    virtual void effacer() {
        ComposantBDP* child = res;
        ComposantBDP* parent = this->getParent();

        if (auto parentComposite = dynamic_cast<CompositeBDP*>(parent)) {
            parentComposite->remplacer(this, child);
            delete this;
        }
        else {
            dynamic_cast<ReservationDecorateur*>(parent)->setRes(child);
            child->setParent(parent);
            delete this;
        }
    }

    virtual void setRes(ComposantBDP* res) {
        this->res = res;
        res->setParent(this);
    }

    virtual ComposantBDP* const getRes() { return res; }

    virtual void accepter(Visiteur* visiteur) override = 0;

    virtual std::string getNom() const override = 0;
protected:
    ComposantBDP* res;
};