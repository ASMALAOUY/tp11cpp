#include <iostream>
#include <cmath>
using namespace std;

class Forme {
public:
    virtual double aire() const = 0;
    virtual void saisir() = 0;
    virtual ~Forme() {}
};

class Cercle : public Forme {
private:
    double rayon;
public:
    void saisir() override {
        cout << "Entrez le rayon du cercle : ";
        cin >> rayon;
    }
    double aire() const override {
        return M_PI * rayon * rayon;
    }
};

class Rectangle : public Forme {
private:
    double longueur, largeur;
public:
    void saisir() override {
        cout << "Entrez la longueur du rectangle : ";
        cin >> longueur;
        cout << "Entrez la largeur du rectangle : ";
        cin >> largeur;
    }
    double aire() const override {
        return longueur * largeur;
    }
};

int main() {
    int n;
    cout << "Combien de formes voulez-vous creer ? ";
    cin >> n;
    Forme** formes = new Forme*[n];
    for (int i = 0; i < n; ++i) {
        int choix;
        cout << " 1. Cercle \n2. Rectangle  \nVotre choix : ";
        cin >> choix;
        if (choix == 1) formes[i] = new Cercle();
        else formes[i] = new Rectangle();
        formes[i]->saisir();
    }
    cout << "\n--- Aires des formes ---\n";
    for (int i = 0; i < n; ++i)
        cout << "Forme " << i + 1 << " : " << formes[i]->aire() << endl;
    for (int i = 0; i < n; ++i) delete formes[i];
    delete[] formes;
    return 0;
}
