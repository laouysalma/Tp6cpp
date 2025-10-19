#include <iostream>
using namespace std;


class Compte {
protected:
    int numero;
    double solde;

public:
    Compte(int n, double s) : numero(n), solde(s) {}

    void deposer(double montant) {
        solde += montant;
    }

    void retirer(double montant) {
        if(montant <= solde)
            solde -= montant;
        else
            cout << "Solde insuffisant !" << endl;
    }

    void afficher() {
        cout << "Numéro : " << numero << ", Solde : " << solde << endl;
    }
};


class CompteEpargne : public Compte {
private:
    double tauxInteret;

public:
    CompteEpargne(int n, double s, double taux) : Compte(n, s), tauxInteret(taux) {}

    void calculerInteret() {
        double interet = solde * tauxInteret / 100.0;
        cout << "Intérêt calculé : " << interet << endl;
    }
};

int main() {
    CompteEpargne ce1(101, 1000.0, 5.0); 

    ce1.afficher();      
    ce1.deposer(200);    
    ce1.retirer(150);    
    ce1.afficher();      
    ce1.calculerInteret();

    return 0;
}
