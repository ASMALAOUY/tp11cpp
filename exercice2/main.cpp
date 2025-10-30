#include <iostream>
using namespace std;

class Paiement {
public:
    virtual void effectuerPaiement(double montant) const = 0;
    virtual ~Paiement() {}
};

class PaiementCarte : public Paiement {
public:
    void effectuerPaiement(double montant) const override {
        cout << "Paiement de " << montant << " DH par carte bancaire." << endl;
    }
};

class PaiementEspece : public Paiement {
public:
    void effectuerPaiement(double montant) const override {
        cout << "Paiement de " << montant << " DH en espèces." << endl;
    }
};

int main() {
    int n;
    cout << "Combien de paiements voulez-vous simuler ? ";
    cin >> n;

    Paiement** paiements = new Paiement*[n];

    for (int i = 0; i < n; ++i) {
        int choix;
        double montant;
        cout << "\n1. Paiement par carte\n2. Paiement en especes\nVotre choix : ";
        cin >> choix;
        cout << "Montant du paiement : ";
        cin >> montant;

        if (choix == 1)
            paiements[i] = new PaiementCarte();
        else
            paiements[i] = new PaiementEspece();

        paiements[i]->effectuerPaiement(montant);
    }

    for (int i = 0; i < n; ++i)
        delete paiements[i];
    delete[] paiements;

    return 0;
}
