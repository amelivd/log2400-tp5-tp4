#pragma once

#include "ReservationDecorateur.hpp"

class ReservationCommentaire : public ReservationDecorateur {
public:
    ReservationCommentaire(ComposantBDP* res, std::string commentaire) : ReservationDecorateur(res), commentaire(commentaire) {}

    virtual ReservationCommentaire* clone() override {
        return new ReservationCommentaire(res->clone(), commentaire, CloneTag{});
    }

    std::string getNom() const override { return commentaire; }

    virtual void accepter(Visiteur* visiteur) override {
        visiteur->visiter(this);
    }

    std::string getCommentaire() const { return commentaire; }
private:
    struct CloneTag {};
    ReservationCommentaire(ComposantBDP* res, std::string commentaire, CloneTag) : ReservationDecorateur(), commentaire(commentaire) {
        this->setRes(res);
    }

    std::string commentaire;
};