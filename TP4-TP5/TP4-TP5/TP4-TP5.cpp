#include "utils.hpp"

#include "CategorieExcursion.hpp"
#include "CategorieHebergement.hpp"
#include "CategorieTransport.hpp"
#include "BDOR.hpp"
#include "Hebergement.hpp"
#include "Vol.hpp"
#include "Excursion.hpp"
#include "Windows.h"

#include "Voyage.hpp"
#include "Segment.hpp"
#include "Journee.hpp"
#include "Reservation.hpp"

#include "ReservationRestaurantHotel.hpp"
#include "ReservationCommentaire.hpp"

#include "CommentaireOffre.hpp"
#include "RabaisOffre.hpp"

#include "AffichageVisiteur.hpp"
#include "InflationVisiteur.hpp"
#include "NombreOffreVisiteur.hpp"

#include <fstream>

#pragma execution_character_set("utf-8")
using namespace std;

void ajouterHebergementsCSV(Categorie* hebergement);
void ajouterVolsCSV(Categorie* transport);
void ajouterExcursionCSV(Categorie* cat);

int main() {
    SetConsoleOutputCP(CP_UTF8);

    // Creation des categories
    BDOR* bdor = new BDOR();
    Categorie* transport = new CategorieTransport(bdor);
    Categorie* hebergement = new CategorieHebergement(bdor);
    Categorie* excursion = new CategorieExcursion(bdor);

    // Remplir BDOR avec les offres
    ajouterVolsCSV(transport);
    ajouterHebergementsCSV(hebergement);
    ajouterExcursionCSV(excursion);
    std::cout << std::endl;

    // Creation du Voyage de Dora
    Voyage* voyageDora = new Voyage("Dora");

    Segment* segmentF1 = new Segment(voyageDora, "France 1ere partie");
    Journee* j1 = new Journee(segmentF1, "2024-10-26");
    Reservation* r1 = new Reservation(j1, transport->getOffre("Air Canada AC 870 2024-10-26"), "uncourriel@gmail.com", "2024-10-25", "Jean");
    Journee* j2 = new Journee(segmentF1, "2024-10-27");
    Reservation* r2 = new Reservation(j2, hebergement->getOffre("Hotel Stella"), "uncourriel@gmail.com", "2024-10-25", "Jean");
    Journee* j3 = new Journee(segmentF1, "2024-10-28");
    Reservation* r3 = new Reservation(j3, excursion->getOffre("Paris Diner-croisiere sur la Seine by Bateaux Mouches"), "uncourriel@gmail.com", "2024-10-25", "Jean");
    Reservation* r4 = new Reservation(j3, hebergement->getOffre("Hotel Stella"), "uncourriel@gmail.com", "2024-10-25", "Jean");

    Segment* segmentP = new Segment(voyageDora, "Portugal");
    Journee* j4 = new Journee(segmentP, "2024-10-29");
    Reservation* r5 = new Reservation(j4, transport->getOffre("TAP Air Portugal TP 441 2024-10-29"), "uncourriel@gmail.com", "2024-10-25", "Jean");
    Reservation* r6 = new Reservation(j4, hebergement->getOffre("Hotel Roma"), "uncourriel@gmail.com", "2024-10-25", "Jean");
    Journee* j5 = new Journee(segmentP, "2024-10-30");
    Reservation* r7 = new Reservation(j5, excursion->getOffre("Visite du Musée Calouste-Gulbenkian"), "uncourriel@gmail.com", "2024-10-25", "Jean");
    Reservation* r8 = new Reservation(j5, hebergement->getOffre("Hotel Roma"), "uncourriel@gmail.com", "2024-10-25", "Jean");
    Journee* j6 = new Journee(segmentP, "2024-10-31");
    Reservation* r9 = new Reservation(j6, transport->getOffre("easyJet 4592 2024-10-31"), "uncourriel@gmail.com", "2024-10-25", "Jean");

    Segment* segmentF2 = new Segment(voyageDora, "France 2ème partie");
    Journee* j7 = new Journee(segmentF2, "2024-10-31");
    Reservation* r10 = new Reservation(j7, hebergement->getOffre("Hotel Stella"), "uncourriel@gmail.com", "2024-10-25", "Jean");
    Journee* j8 = new Journee(segmentF2, "2024-11-01");
    Reservation* r11 = new Reservation(j8, excursion->getOffre("Visite guidée pour voir les chefs-d'œuvre du musée du Louvre"), "uncourriel@gmail.com", "2024-10-25", "Jean");
    Reservation* r12 = new Reservation(j8, hebergement->getOffre("Hotel Stella"), "uncourriel@gmail.com", "2024-10-25", "Jean");
    Journee* j9 = new Journee(segmentF2, "2024-11-02");
    Reservation* r13 = new Reservation(j9, excursion->getOffre("Visite guidée à Versailles et accès prioritaire avec transfert depuis l'hôtel au départ de Paris"), "uncourriel@gmail.com", "2024-10-25", "Jean");
    Reservation* r14 = new Reservation(j9, hebergement->getOffre("Hotel Stella"), "uncourriel@gmail.com", "2024-10-25", "Jean");
    Journee* j10 = new Journee(segmentF2, "2024-11-03");
    Reservation* r15 = new Reservation(j10, transport->getOffre("Air Transat 111 2024-11-03"), "uncourriel@gmail.com", "2024-10-25", "Jean");
    std::cout << std::endl;

    // Copie du voyage de Dora pour Diego
    Voyage* voyageDiego = voyageDora->copie("Diego");
    voyageDiego->enleverSegment("Portugal");
    Segment* segmentEDiego = new Segment(voyageDiego, "Espagne");
    Journee* j11 = new Journee(segmentEDiego, "2024-10-29");
    Reservation* r16 = new Reservation(j11, transport->getOffre("Air Europa 1026"), "uncourriel@gmail.com", "2024-10-25", "Jean");
    Reservation* r17 = new Reservation(j11, hebergement->getOffre("Far Home Atocha"), "uncourriel@gmail.com", "2024-10-25", "Jean");
    Journee* j12 = new Journee(segmentEDiego, "2024-10-30");
    Reservation* r18 = new Reservation(j12, excursion->getOffre("Excursion d'une journée à Tolède (de Madrid)"), "uncourriel@gmail.com", "2024-10-25", "Jean");
    Reservation* r19 = new Reservation(j12, hebergement->getOffre("Far Home Atocha"), "uncourriel@gmail.com", "2024-10-25", "Jean");
    Journee* j13 = new Journee(segmentEDiego, "2024-10-31");
    Reservation* r20 = new Reservation(j13, transport->getOffre("Air Europa 1025"), "uncourriel@gmail.com", "2024-10-25", "Jean");
    std::cout << std::endl;

    // Copie du voyage de Diego pour Alicia
    Voyage* voyageAlicia = voyageDiego->copie("Alicia");
    std::cout << std::endl;

    std::cout << "Total des frais pour le Voyage de Dora ($ CA): " << voyageDora->getPrixCAD() << std::endl;
    std::cout << "Total des frais pour le Voyage de Diego ($ CA): " << voyageDiego->getPrixCAD() << std::endl;
    std::cout << "Total des frais pour le Voyage d'Alicia ($ CA): " << voyageAlicia->getPrixCAD() << std::endl;
    std::cout << std::endl;

    // Modifications de reservations
    ReservationRestaurantHotel* rmod1 = new ReservationRestaurantHotel(r2, r2->getParent()->getNom(), 19);
    ReservationRestaurantHotel* rmod2 = new ReservationRestaurantHotel(r10, r10->getParent()->getNom(), 19);
    ReservationCommentaire* rmod3 = new ReservationCommentaire(rmod2, "Excellent service!");
    rmod2->annuler();

    // Modification des offres
    CommentaireOffre* commentaire = new CommentaireOffre(excursion->getOffre("Visite guidée pour voir les chefs-d'œuvre du musée du Louvre"), "Rabais de 5 dollars canadiens au Louvre pour les etudiants de Polytechnique Montreal!\n");
    RabaisOffre* rabais = new RabaisOffre(excursion->getOffre("Visite guidée pour voir les chefs-d'œuvre du musée du Louvre"), 5);
    InflationVisiteur* inflationVisiteur2pourcent = new InflationVisiteur(0.02);
    InflationVisiteur* inflationVisiteur3pourcent = new InflationVisiteur(0.03);
    hebergement->accepter(inflationVisiteur3pourcent);
    excursion->accepter(inflationVisiteur2pourcent);
    transport->accepter(inflationVisiteur2pourcent);

    // Calcul du nombre d'offres de réservations dans la BDOR
    NombreOffreVisiteur* nombreOffreVisiteur = new NombreOffreVisiteur();
    bdor->accepter(nombreOffreVisiteur);
    int nombreOffre = nombreOffreVisiteur->getNombreOffre();

    // Affichage des voyages
    AffichageVisiteur* affichageVisiteur = new AffichageVisiteur();
    voyageDora->accepter(affichageVisiteur);
    std::cout << std::endl;
    voyageDiego->accepter(affichageVisiteur);
    std::cout << std::endl;
    voyageAlicia->accepter(affichageVisiteur);
    std::cout << std::endl;

    std::cout << "Total du nombre d'offres de réservations dans la BDOR: " << nombreOffre << std::endl;

    delete affichageVisiteur;
    delete bdor;
    delete voyageDora;
    delete voyageDiego;
    delete voyageAlicia;
    return 0;
}

void ajouterExcursionCSV(Categorie* cat) {
    ifstream fin("Excursions.csv");
    fin.imbue(std::locale("en_US.UTF-8"));
    string line, val;
    getline(fin, line);
    while (getline(fin, line)) {
        stringstream ss(line);
        vector<string> row;

        while (getline(ss, val, ',')) {
            row.push_back(val);
        }
        new Excursion(cat, stringToDevise(row[4]), row[0], stoi(row[3]), row[1], stoi(row[2]));
    }
}

void ajouterVolsCSV(Categorie* cat) {
    ifstream fin("Transports.csv");
    fin.imbue(std::locale("en_US.UTF-8"));
    if (!fin.is_open()) {
        cerr << "Un probleme est survenu lors de la lecture des donnees." << endl;
 
    }
    string line;
    string val;
    getline(fin, line);
    while (getline(fin, line)) {
        stringstream ss(line);
        vector<string> row;

        while (getline(ss, val, ',')) {
            row.push_back(val);
        }

        new Vol(
            cat,
            stringToDevise(row[13]),
            row[0],
            stoi(row[12]),
            row[9],
            row[10],
            parseDateTime(row[7], row[8]),
            parseDateTime(row[5], row[6]),
            row[4],
            row[3],
            row[2],
            row[1],
            row[11] == "true" ? 1 : 0);
    }
}

void ajouterHebergementsCSV(Categorie* cat) {
    ifstream fin("Hebergements.csv");
    string line, val;
    getline(fin, line);
    while (getline(fin, line)) {
        stringstream ss(line);
        vector<string> row;

        while (getline(ss, val, ',')) {
            row.push_back(val);
        }

        new Hebergement(cat, stringToDevise(row[5]), row[0], stoi(row[4]), row[1], row[2], stod(row[3]));
    }
}