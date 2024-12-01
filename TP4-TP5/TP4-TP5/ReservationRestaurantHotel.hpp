#pragma once

#include "ReservationModification.hpp"

class ReservationRestaurantHotel : public ReservationModification {
public:
    ReservationRestaurantHotel(ComposantBDP* res, std::string date, int heure) : ReservationRestaurantHotel(res, Devise::CAD, 0, date, heure) {}

    ReservationRestaurantHotel(ComposantBDP* res, Devise devise, double prix, std::string date, int heure)
        : ReservationModification(res, devise, prix), heure(heure), date(date) {
    }

    virtual ReservationRestaurantHotel* clone() override {
        return new ReservationRestaurantHotel(res->clone(), devise, prix, heure, CloneTag{});
    }

    virtual void accepter(Visiteur* visiteur) override {
        visiteur->visiter(this);
    }

    std::string getDate() const { return date; }
    int getHeure() const { return heure; }
private:
    struct CloneTag {};
    ReservationRestaurantHotel(ComposantBDP* res, Devise devise, double prix, int heure, CloneTag) : ReservationModification(), heure(heure) {
        this->setRes(res);
        this->devise = devise;
        this->prix = prix;
    }

    int heure;
    std::string date;
};