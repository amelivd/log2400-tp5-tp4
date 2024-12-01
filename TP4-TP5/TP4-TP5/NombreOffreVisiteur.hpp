#pragma once

#include "Visiteur.hpp"

#include "Offre.hpp"
#include "Categorie.hpp"
#include "CommentaireOffre.hpp"
#include "RabaisOffre.hpp"
#include "BDOR.hpp"

class NombreOffreVisiteur : public Visiteur {
public:

    int getNombreOffre() const {
        return nombreOffre;
    }

    virtual void visiter(Journee* journee) {}
    virtual void visiter(Reservation* reservation) {}
    virtual void visiter(Voyage* voyage) {}
    virtual void visiter(Segment* segment) {}
    virtual void visiter(ReservationCommentaire* reservationCommentaire) {}
    virtual void visiter(ReservationRestaurantHotel* reservationRestaurantHotel) {}

    virtual void visiter(RabaisOffre* rabaisOffre) {
        nombreOffre++;
    }

    virtual void visiter(CommentaireOffre* commentaireOffre) {
        nombreOffre++;
    }

    virtual void visiter(Offre* offre) {
        nombreOffre++;
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
    int nombreOffre = 0;
};