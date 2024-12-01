#include "Reservation.hpp"
#include "OffreDecorateur.hpp"

Reservation::Reservation(CompositeBDP* parent, ComposantBDOR* offre, std::string adresseCourrielVendeur, std::string dateAchat, std::string nomContactVendeur)
    : ComposantBDP(parent), offre(offre), adresseCourrielVendeur(adresseCourrielVendeur), dateAchat(dateAchat), nomContactVendeur(nomContactVendeur) {

    std::cout << "      Reservation creee : "
        << parent->getParent()->getParent()->getNom() << "/" << parent->getNom()
        << "/" << offre->getNom() << "!" << std::endl;

    parent->ajouter(this);

    if (auto castedOffre = dynamic_cast<OffreDecorateur*>(offre)) {
        castedOffre->subscribe(this);
    }
    else if (auto castedOffre = dynamic_cast<Offre*>(offre)) {
        castedOffre->subscribe(this);
    }
}

void Reservation::update(ComposantBDOR* nouvelleOffre) {
    offre = nouvelleOffre;

    if (auto castedOffre = dynamic_cast<OffreDecorateur*>(nouvelleOffre)) {
        castedOffre->subscribe(this);
    }
    else if (auto castedOffre = dynamic_cast<Offre*>(nouvelleOffre)) {
        castedOffre->subscribe(this);
    }
}

double Reservation::getPrixCAD() const {
    return offre->getPrixCAD();
}
double Reservation::getPrixEURO() const {
    return offre->getPrixEURO();
}

Reservation* Reservation::clone() {
    return new Reservation(this, CloneTag());
}

Reservation::Reservation(Reservation* res, CloneTag) : ComposantBDP(), offre(res->offre), adresseCourrielVendeur(res->adresseCourrielVendeur), dateAchat(res->dateAchat), nomContactVendeur(res->nomContactVendeur) {
    if (auto castedOffre = dynamic_cast<OffreDecorateur*>(offre)) {
        castedOffre->subscribe(this);
    }
    else if (auto castedOffre = dynamic_cast<Offre*>(offre)) {
        castedOffre->subscribe(this);
    }
}
