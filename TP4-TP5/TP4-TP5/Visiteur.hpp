#pragma once

class Journee;
class Reservation;
class Voyage;
class Segment;
class ReservationCommentaire;
class ReservationRestaurantHotel;
class RabaisOffre;
class CommentaireOffre;
class Offre;
class Categorie;
class BDOR;

class Visiteur {
public:
    Visiteur() = default;
    virtual ~Visiteur() = default;

    virtual void visiter(Journee* journee) = 0;
    virtual void visiter(Reservation* reservation) = 0;
    virtual void visiter(Voyage* voyage) = 0;
    virtual void visiter(Segment* segment) = 0;
    virtual void visiter(ReservationCommentaire* reservationCommentaire) = 0;
    virtual void visiter(ReservationRestaurantHotel* reservationRestaurantHotel) = 0;
    virtual void visiter(RabaisOffre* rabaisOffre) = 0;
    virtual void visiter(CommentaireOffre* commentaireOffre) = 0;
    virtual void visiter(Offre* offre) = 0;
    virtual void visiter(Categorie* categorie) = 0;
    virtual void visiter(BDOR* bdor) = 0;
};

