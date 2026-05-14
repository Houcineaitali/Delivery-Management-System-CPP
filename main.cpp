#include <iostream>
#include <memory>
#include <vector>
#include "Core.h"       
#include "Carriers.cpp"    
#include "Manager.cpp"    

using namespace std;

void displayMenu() {
    cout << "\n--- Logistic Simulator System ---" << endl;
    cout << "1. Ajouter un nouveau colis" << endl;
    cout << "2. Afficher le rapport de livraison" << endl;
    cout << "3. Quitter" << endl;
    cout << "Choix : ";
}

int main() {
    // 1. إنشاء محرك النظام وتعبئة الأسطول (Fleet)
    DeliverySystem system; 
    system.addCarrier(make_unique<Truck>());
    system.addCarrier(make_unique<Drone>());
    system.addCarrier(make_unique<Bike>());

    int choice;
    do {
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            double weight;
            int fragileInput;
            
            cout << "Poids du colis (kg) : ";
            cin >> weight;
            cout << "Le colis est-il fragile ? (1: Oui, 0: Non) : ";
            cin >> fragileInput;

            Package p = {weight, (fragileInput == 1)   }
             ;

            system.ship(p);
        }

    } while (choice != 3);

    cout << "Au revoir!" << endl;
    return 0;
}
