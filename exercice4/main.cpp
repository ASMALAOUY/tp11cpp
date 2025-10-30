#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NoeudFichier {
public:
    virtual string nom() const = 0;
    virtual int taille() const = 0;
    virtual ~NoeudFichier() {}
};

class Fichier : public NoeudFichier {
private:
    string _nom;
    int _taille;
public:
    Fichier(const string& nom, int taille) : _nom(nom), _taille(taille) {}
    string nom() const override { return _nom; }
    int taille() const override { return _taille; }
};

class Dossier : public NoeudFichier {
private:
    string _nom;
    vector<NoeudFichier*> enfants;
public:
    Dossier(const string& nom) : _nom(nom) {}
    string nom() const override { return _nom; }
    int taille() const override {
        int total = 0;
        for (auto e : enfants) total += e->taille();
        return total;
    }
    void ajouter(NoeudFichier* nf) {
        enfants.push_back(nf);
    }
    const vector<NoeudFichier*>& lister() const {
        return enfants;
    }
    ~Dossier() {
        for (auto e : enfants)
            delete e;
    }
};

int main() {
    Dossier* racine = new Dossier("Racine");

    int n;
    cout << "Combien de fichiers/dossiers voulez-vous ajouter a la racine ? ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int type;
        cout << "Type (1 = Fichier, 2 = Dossier) : ";
        cin >> type;
        cin.ignore();

        if (type == 1) {
            string nom;
            int taille;
            cout << "Nom du fichier : ";
            getline(cin, nom);
            cout << "Taille du fichier : ";
            cin >> taille;
            racine->ajouter(new Fichier(nom, taille));
        } else {
            string nom;
            cout << "Nom du dossier : ";
            cin.ignore();
            getline(cin, nom);
            Dossier* sousDossier = new Dossier(nom);

            int m;
            cout << "Combien de fichiers dans ce dossier ? ";
            cin >> m;
            for (int j = 0; j < m; ++j) {
                string nomF;
                int tailleF;
                cout << "Nom du fichier : ";
                cin.ignore();
                getline(cin, nomF);
                cout << "Taille du fichier : ";
                cin >> tailleF;
                sousDossier->ajouter(new Fichier(nomF, tailleF));
            }
            racine->ajouter(sousDossier);
        }
    }

    cout << "\nTaille totale du dossier racine : " << racine->taille() << " unités\n";

    delete racine;
    return 0;
}
