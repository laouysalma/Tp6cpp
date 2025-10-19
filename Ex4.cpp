#include <iostream>
#include <string>
using namespace std;


class Employe {
protected:
    string nom;
    int id;
    float salaireDeBase;

public:
    Employe(string n, int i, float s) : nom(n), id(i), salaireDeBase(s) {}

    virtual void afficherInfos() {
        cout << "Nom : " << nom << ", ID : " << id 
             << ", Salaire de base : " << salaireDeBase << "€" << endl;
    }

    virtual ~Employe() {
        cout << "Destruction de l'employé " << nom << endl;
    }
};

class Permanent : public Employe {
private:
    float primeAnnuelle;

public:
    Permanent(string n, int i, float s, float prime) 
        : Employe(n, i, s), primeAnnuelle(prime) {}

    void afficherInfos() override {
        cout << "Permanent - Nom : " << nom 
             << ", ID : " << id 
             << ", Salaire de base : " << salaireDeBase 
             << "€, Prime annuelle : " << primeAnnuelle << "€" << endl;
    }
};


class Contractuel : public Employe {
private:
    int dureeContrat;  
    float tauxHoraire;

public:
    Contractuel(string n, int i, float s, int duree, float taux) 
        : Employe(n, i, s), dureeContrat(duree), tauxHoraire(taux) {}

    void afficherInfos() override {
        cout << "Contractuel - Nom : " << nom 
             << ", ID : " << id 
             << ", Salaire de base : " << salaireDeBase 
             << "€, Durée contrat : " << dureeContrat 
             << " mois, Taux horaire : " << tauxHoraire << "€/h" << endl;
    }

    float calculerSalaireMensuel(int heures) {
        return tauxHoraire * heures;
    }
};

int main() {
    Employe* employes[3];

    employes[0] = new Permanent("Alice", 101, 3000.0, 500.0);
    employes[1] = new Contractuel("Bob", 102, 0.0, 12, 20.0);
    employes[2] = new Permanent("Charlie", 103, 3200.0, 700.0);

    for(int i = 0; i < 3; i++) {
        employes[i]->afficherInfos();
    }

    Contractuel* c = dynamic_cast<Contractuel*>(employes[1]);
    if(c) {
        cout << "Salaire mensuel Bob pour 160h : " << c->calculerSalaireMensuel(160) << "€" << endl;
    }

    
    for(int i = 0; i < 3; i++) {
        delete employes[i];
    }

    return 0;
}
