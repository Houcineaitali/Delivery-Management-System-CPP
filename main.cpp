#include <iostream>
#include <memory>
#include "Core.h"
#include "Carriers.cpp"
#include "Manager.cpp"

using namespace std;

int main() {
    DeliverySystem system;
    
    // Initialisation automatique de la flotte logistique
    system.addCarrier(make_unique<Drone>()); // Priorité au drone si colis léger/fragile
    system.addCarrier(make_unique<Truck>()); // Le camion prend le relais sinon

    int choice = 0;
    do {
        cout << "\n=========================================" << endl;
        cout << "      CENTRE LOGISTIQUE SIMULATOR        " << endl;
        cout << "=========================================" << endl;
        cout << "1. Enregistrer et expedier un colis" << endl;
        cout << "2. Quitter le simulateur" << endl;
        cout << "Votre choix : ";
        cin >> choice;

        if (choice == 1) {
            double w;
            int f;
            cout << "\nPoids du colis (en kg) : "; 
            cin >> w;
            cout << "Le colis est-il fragile ? (1: Oui / 0: Non) : "; 
            cin >> f;

            // Instanciation du colis
            Package p = {w, (f == 1)};
            
            // Lancement du processus d'attribution automatique
            system.ship(p);
        }
    } while (choice != 2);

    cout << "\nArret du systeme. Rapport enregistre dans 'rapport_livraison.txt'." << endl;
    return 0;
}
