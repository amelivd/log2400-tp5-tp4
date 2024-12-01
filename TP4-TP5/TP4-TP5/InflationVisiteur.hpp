#pragma once

#include "Visiteur.hpp"

#include "Offre.hpp"
#include "Categorie.hpp"
#include "CommentaireOffre.hpp"
#include "RabaisOffre.hpp"


class InflationVisiteur : public Visiteur {
public:
    InflationVisiteur(double inflation) {
        this->inflation = inflation;
    }

    virtual void visiter(Journee* journee) {}
    virtual void visiter(Reservation* reservation) {}
    virtual void visiter(Voyage* voyage) {}
    virtual void visiter(Segment* segment) {}
    virtual void visiter(ReservationCommentaire* reservationCommentaire) {}
    virtual void visiter(ReservationRestaurantHotel* reservationRestaurantHotel) {}

    virtual void visiter(RabaisOffre* rabaisOffre) {
        ComposantBDOR* enfant = rabaisOffre->getOffre();
        Offre* offre = dynamic_cast<Offre*>(enfant);
        while (offre == nullptr) {
            enfant = dynamic_cast<OffreDecorateur*>(enfant)->getOffre();
            offre = dynamic_cast<Offre*>(enfant);
        }
        offre->accepter(this);
    }

    virtual void visiter(CommentaireOffre* commentaireOffre) {
        ComposantBDOR* enfant = commentaireOffre->getOffre();
        Offre* offre = dynamic_cast<Offre*>(enfant);
        while (offre == nullptr) {
            enfant = dynamic_cast<OffreDecorateur*>(enfant)->getOffre();
            offre = dynamic_cast<Offre*>(enfant);
        }
        offre->accepter(this);
    }

    virtual void visiter(Offre* offre) {
        double prix = offre->getPrixUnitaire();
        prix *= (1 + inflation);
        offre->setPrixUnitaire(prix);
    }

    virtual void visiter(Categorie* categorie) {
        for (ComposantBDOR* enfant : categorie->getEnfants()) {
            enfant->accepter(this);
        }
    }

    virtual void visiter(BDOR* bdor) {
        for (ComposantBDOR* categorie : bdor->getEnfants()) {
            categorie->accepter(this);
        }
    }
private:
    double inflation = 0;
};