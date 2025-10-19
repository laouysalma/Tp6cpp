#include <iostream>
#include <string>
using namespace std;

class Produit {
protected:
    string nom;
    double prix;

public:
    Produit(string n, double p) : nom(n), prix(p) {}

    virtual void afficherInfos() {
        cout << "Produit : " << nom << ", Prix : " << prix << "€" << endl;
    }

    virtual ~Produit() {}
};

class ProduitAlimentaire : public Produit {
private:
    string dateExpiration;

public:
    ProduitAlimentaire(string n, double p, string date) 
        : Produit(n, p), dateExpiration(date) {}

    void afficherInfos() override {
        cout << "Produit Alimentaire : " << nom 
             << ", Prix : " << prix 
             << "€, Date d'expiration : " << dateExpiration << endl;
    }
};


class ProduitElectronique : public Produit {
private:
    int garantie; 

public:
    ProduitElectronique(string n, double p, int g) 
        : Produit(n, p), garantie(g) {}

    void afficherInfos() override {
        cout << "Produit Électronique : " << nom 
             << ", Prix : " << prix 
             << "€, Garantie : " << garantie << " mois" << endl;
    }
};

int main() {
    ProduitAlimentaire pa("Lait", 1.5, "2025-11-30");
    ProduitElectronique pe("Smartphone", 699.99, 24);

    pa.afficherInfos();
    pe.afficherInfos();

    return 0;
}
