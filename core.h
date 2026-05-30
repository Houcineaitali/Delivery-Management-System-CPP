#ifndef CORE_H
#define CORE_H
#include <string>

// Structure représentant les données d'un colis
struct Package {
    double weight;     // Poids du colis en kg
    bool isFragile;    // État du colis (true si fragile, false sinon)
};

// Interface/Classe de base abstraite pour les transporteurs
class Carrier {
public:
    virtual ~Carrier() {} // Destructeur virtuel pour une libération propre de la mémoire
    
    // Méthodes virtuelles pures (à implémenter obligatoirement par les classes dérivées)
    virtual bool canDeliver(const Package& p) const = 0;
    virtual double getPrice(const Package& p) const = 0;
    virtual std::string getName() const = 0;
};
#endif
