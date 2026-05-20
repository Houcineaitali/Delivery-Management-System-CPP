#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Package {
public:
    int id;
    double weight;
    bool fragile;
    string status;

    Package(int i, double w, bool f) {
        id = i;
        weight = w;
        fragile = f;
        status = "En attente";
    }
};

class Manager {
private:
    vector<Package> packages;

public:

    // Ajouter colis
    void addPackage(Package p) {
        packages.push_back(p);

        cout << "Colis ajoute avec succes !" << endl;
    }

    // Modifier statut
    void updateStatus(int id, string newStatus) {

        for (int i = 0; i < packages.size(); i++) {

            if (packages[i].id == id) {

                packages[i].status = newStatus;

                cout << "Statut mis a jour !" << endl;

                return;
            }
        }

        cout << "Colis introuvable !" << endl;
    }

    // Afficher tous les colis
    void showPackages() {

        cout << "\n===== Liste des Colis =====" << endl;

        for (int i = 0; i < packages.size(); i++) {

            cout << "ID : " << packages[i].id << endl;
            cout << "Poids : " << packages[i].weight << " kg" << endl;

            if (packages[i].fragile)
                cout << "Type : Fragile" << endl;
            else
                cout << "Type : Standard" << endl;

            cout << "Statut : " << packages[i].status << endl;

            cout << "------------------------" << endl;
        }
    }
};
