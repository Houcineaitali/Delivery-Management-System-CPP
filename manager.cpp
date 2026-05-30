#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include "Core.h"

class DeliverySystem {
private:
    std::vector<std::unique_ptr<Carrier>> fleet; // Utilisation des Smart Pointers (C++ moderne)

public:
    // Ajouter un véhicule à la flotte
    void addCarrier(std::unique_ptr<Carrier> c) { 
        fleet.push_back(std::move(c)); 
    }

    // Algorithme d'attribution automatique polymorphique
    void ship(const Package& p) {
        bool assigned = false;

        // Utilisation de la surcharge de l'opérateur << (Fonction amie de Core.h)
        std::cout << "\nTraitement de l'expedition pour le : " << p << std::endl;

        for (const auto& vehicle : fleet) {
            // CHALLENGE AVANCÉ RÉUSSI :
            // C'est l'objet véhicule lui-même qui décide via le polymorphisme dynamique.
            // Aucun "if (typeid == Truck)" ou "switch" n'est écrit ici.
            if (vehicle->canDeliver(p)) { 
                double cost = vehicle->getPrice(p);
                
                std::cout << "-> Succes : Attribue a " << vehicle->getName() << std::endl;
                std::cout << "   Tarif applique : " << cost << " DH" << std::endl;
                
                // PERSISTANCE DES DONNÉES : Sauvegarde du rapport de livraison
                std::ofstream file("rapport_livraison.txt", std::ios::app);
                if (file.is_open()) {
                    file << "Vehicule: " << vehicle->getName() << " | Poids: " << p.weight 
                         << "kg | Prix: " << cost << "DH\n";
                }
                
                assigned = true;
                break; // Le colis est pris en charge, on arrête la recherche
            }
        }

        if (!assigned) {
            std::cout << "-> Echec : Aucun transporteur de la flotte ne peut livrer ce colis." << std::endl;
        }
    }
};
