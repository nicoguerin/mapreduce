#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

void mostraMenu() {
    cout << "1. Llegir paraules d'un fitxer" << endl;
    cout << "2. Llegir lletres d'un fitxer" << endl;
    cout << "3. Sortir" << endl;
}

bool esSeparador(char c) {
    return c==' ' or c==';' or c==':' or c==',' or c=='.' or c=='\n';
}

string generaRutaFitxer() {
    string ubicacioFitxer = "./fitxers/", nomFitxer;

    cout << "Introdueix la ruta del fitxer (nom_fitxer.txt): ";
    cin >> nomFitxer;
    ubicacioFitxer += nomFitxer;

    return ubicacioFitxer;
}

void llegeixParaulesFitxer(ifstream& f, map<string, int>& freq, string ubicacioFitxer) {
    string cadenaAct = "";
    while (f) {
        char act = f.get();
        if (esSeparador(act)) {
            if (cadenaAct!="") {
                ++freq[cadenaAct];
                cadenaAct = "";
            }
        }
        else cadenaAct += act;
    }

    ofstream resum("./fitxers/resumParaules.txt");
    resum << "APARICIONS DE CADA PARAULA DEL FITXER " << ubicacioFitxer;
    for (auto it : freq) resum << endl << it.first << ": " << it.second;
    f.close();
}

void llegeixLletresFitxer(ifstream& f, map<char, int>& freq, string ubicacioFitxer) {
    char act = f.get();
    while (f) {
        if (!esSeparador(act)) ++freq[act];
        act = f.get();
    }

    ofstream resum("./fitxers/resumLletres.txt");
    resum << "APARICIONS DE CADA LLETRA DEL FITXER " << ubicacioFitxer;
    for (auto it : freq) resum << endl << it.first << ": " << it.second;
    f.close();
}

int main() {
    int opcio = 0;
    while (opcio!=3) {
        mostraMenu();
        cout << "Introdueix una opcio: "; cin >> opcio;

        if (opcio==3) cout << "Sortint del programa..." << endl;
        else {
            string ubicacioFitxer = generaRutaFitxer();
            ifstream f(ubicacioFitxer);

            if (!f) cout << "No s'ha pogut obrir el fitxer" << endl;
            else {
                if (opcio==1) {
                    map<string, int> freq;
                    llegeixParaulesFitxer(f, freq, ubicacioFitxer);
                }
                else if (opcio==2) {
                    map<char, int> freq;
                    llegeixLletresFitxer(f, freq, ubicacioFitxer);
                }
                
                f.close();
                cout << endl;
            }
        }
    }
}