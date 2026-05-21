#include <iostream>
#include <memory>
#include "core.h"
#include "carriers.cpp"
#include "manager.cpp"

using namespace std;

void showHeader() {
    cout << "=================================================" << endl;
    cout << "   BIENVENUE DANS LE SYSTEME LOGITECH SOLUTIONS  " << endl;
    cout << "=================================================" << endl;
}

int main() {
    // إنشاء النظام
    DeliverySystem system;

    // تهيئة الأسطول (التعبئة تتم تلقائياً عند الإقلاع)
    system.addCarrier(make_unique<Drone>()); // يتم فحص الدرون أولاً للسرعة والهشاشة
    system.addCarrier(make_unique<Bike>());  // ثم الدراجة للاقتصاد
    system.addCarrier(make_unique<Truck>()); // ثم الشاحنة للأوزان الثقيلة

    int choice = 0;
    
    do {
        showHeader();
        cout << "1. Expédier un nouveau colis" << endl;
        cout << "2. Quitter le centre de contrôle" << endl;
        cout << "Votre choix : ";
        cin >> choice;

        if (choice == 1) {
            double weight;
            int fragileInput;

            cout << "\n--- Saisie des informations du colis ---" << endl;
            cout << "Entrez le poids du colis (en kg) : ";
            cin >> weight;
            cout << "Le colis est-il fragile ? (1 = Oui / 0 = Non) : ";
            cin >> fragileInput;

            // بناء كائن الطرد
            Package p = { weight, (fragileInput == 1) };

            // إرسال الطرد للمحرك الذكي
            system.ship(p);
            cout << "\n=================================================\n" << endl;
        }

    } while (choice != 2);

    cout << "\nMerci d'avoir utilisé LogiTech Solutions. Fin du programme." << endl;
    return 0;
}
