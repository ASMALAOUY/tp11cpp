#include <iostream>
using namespace std;

int main() {
    int choix;

    cout << "Choisissez un animal :" << endl;
    cout << "1. Chien" << endl;
    cout << "2. Chat" << endl;
    cout << "3. Vache" << endl;
    cout << "Votre choix : ";
    cin >> choix;

    switch (choix) {
        case 1:
            cout << "Je suis un animal." << endl;
            cout << "Wouf !" << endl;
            break;
        case 2:
            cout << "Je suis un animal." << endl;
            cout << "Miaou !" << endl;
            break;
        case 3:
            cout << "Je suis un animal." << endl;
            cout << "Meuh !" << endl;
            break;
        default:
            cout << "Choix invalide !" << endl;
            break;
    }

    return 0;
}
