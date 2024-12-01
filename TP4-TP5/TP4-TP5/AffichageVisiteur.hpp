#pragma once

#include <stack>
#include <cmath>

#include "Visiteur.hpp"
#include "utils.hpp"

#include "BDOR.hpp"
#include "Categorie.hpp"
#include "Offre.hpp"
#include "Journee.hpp"
#include "Reservation.hpp"
#include "Voyage.hpp"
#include "Segment.hpp"
#include "ReservationCommentaire.hpp"
#include "ReservationRestaurantHotel.hpp"
#include "RabaisOffre.hpp"
#include "CommentaireOffre.hpp"
#include "Offre.hpp"

class AffichageVisiteur : public Visiteur {
public:
    AffichageVisiteur() = default;

    virtual void visiter(Journee* journee) {
        std::cout << "  Journee " << journee->getNom() << ":" << std::endl;
        for (auto reservation : journee->getEnfants()) {
            reservation->accepter(this);
        }
    }

    virtual void visiter(Reservation* reservation) {
        std::cout << "    Reservation " << reservation->getNom();
        std::cout << ", prix total ($ CA): " << (int)std::round(reservation->getPrixCAD()) << std::endl;
        reservation->getOffre()->accepter(this);
    }

    virtual void visiter(Voyage* voyage) {
        std::cout << voyage->getNom() << ":" << std::endl;
        for (auto segment : voyage->getEnfants()) {
            segment->accepter(this);
        }
    }

    virtual void visiter(Segment* segment) {
        for (auto journee : segment->getEnfants()) {
            journee->accepter(this);
        }
    }

    virtual void visiter(ReservationCommentaire* reservationCommentaire) {
        std::stack<ComposantBDP*> pile;

        ComposantBDP* enfant = reservationCommentaire->getRes();
        auto enfantCast = dynamic_cast<Reservation*>(enfant);

        while (!enfantCast) {
            pile.push(enfant);
            enfant = dynamic_cast<ReservationDecorateur*>(enfant)->getRes();
            enfantCast = dynamic_cast<Reservation*>(enfant);
        }

        enfantCast->accepter(this);

        while (!pile.empty()) {
            pile.top()->accepter(this);
            pile.pop();
        }

        std::cout << "      Commentaire: " << reservationCommentaire->getCommentaire() << std::endl;
    }

    virtual void visiter(ReservationRestaurantHotel* reservationRestaurantHotel) {
        std::stack<ComposantBDP*> pile;

        ComposantBDP* enfant = reservationRestaurantHotel->getRes();
        auto enfantCast = dynamic_cast<Reservation*>(enfant);

        while (!enfantCast) {
            pile.push(enfant);
            enfant = dynamic_cast<ReservationDecorateur*>(enfant)->getRes();
            enfantCast = dynamic_cast<Reservation*>(enfant);
        }

        enfantCast->accepter(this);

        while (!pile.empty()) {
            pile.top()->accepter(this);
            pile.pop();
        }

        std::cout << "      Reservation Restaurant de l'" << enfantCast->getNom() << " pour le ";
        std::cout << formatDate(reservationRestaurantHotel->getDate()) << " à ";
        std::cout << reservationRestaurantHotel->getHeure() << "h." << std::endl;
    }

    virtual void visiter(RabaisOffre* rabaisOffre) {
        std::stack<ComposantBDOR*> pile;
        ComposantBDOR* enfant = rabaisOffre->getOffre();

        while (dynamic_cast<OffreDecorateur*>(enfant)) {
            pile.push(enfant);
            enfant = dynamic_cast<OffreDecorateur*>(enfant)->getOffre();
        }

        enfant->accepter(this);

        while (!pile.empty()) {
            pile.top()->accepter(this);
            pile.pop();
        }
    }

    virtual void visiter(CommentaireOffre* commentaireOffre) {
        std::stack<ComposantBDOR*> pile;
        ComposantBDOR* enfant = commentaireOffre->getOffre();

        while (dynamic_cast<OffreDecorateur*>(enfant)) {
            pile.push(enfant);
            enfant = dynamic_cast<OffreDecorateur*>(enfant)->getOffre();
        }

        enfant->accepter(this);

        while (!pile.empty()) {
            pile.top()->accepter(this);
            pile.pop();
        }

        std::cout << "      Commentaire: " << commentaireOffre->getCommentaire() << std::endl;
    }

    virtual void visiter(Offre* offre) { return; }

    virtual void visiter(Categorie* categorie) { return; }

    virtual void visiter(BDOR* bdor) { return; }
};
