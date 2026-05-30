
#include "Core.h"

// Classe Camion : spécialisée pour les colis lourds
class Truck : public Carrier {
public:
    std::string getName() const override { return "Camion 🚚"; }
    
    // Le camion accepte les colis lourds allant jusqu'à 200 kg
    bool canDeliver(const Package& p) const override { return p.weight <= 200; }
    
    // Le prix du camion dépend du poids du colis
    double getPrice(const Package& p) const override { return p.weight * 5; }
};

// Classe Drone : spécialisée pour les colis légers et fragiles
class Drone : public Carrier {
public:
    std::string getName() const override { return "Drone 🚁"; }
    
    // Le drone accepte uniquement les colis légers (<= 5kg) ET fragiles
    bool canDeliver(const Package& p) const override { return p.weight <= 5 && p.isFragile; }
    
    // Le drone applique un tarif fixe pour la livraison rapide
    double getPrice(const Package& p) const override { return 100; }
};
