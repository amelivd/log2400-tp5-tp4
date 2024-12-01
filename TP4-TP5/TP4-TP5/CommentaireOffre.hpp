#pragma once

#include "OffreDecorateur.hpp"

class CommentaireOffre : public OffreDecorateur {
public:
    CommentaireOffre(ComposantBDOR* offre, std::string commentaire) : OffreDecorateur(offre), commentaire(commentaire) {}
    std::string getCommentaire() const { return commentaire; }

    virtual void accepter(Visiteur* v) override { v->visiter(this); }
private:
    std::string commentaire;
};