#include <iostream>
using namespace std;

void deportes(string deportes[5]) {
    string deportesx[5] = {"futbol", "tenis", "baloncesto", "voley", "natacion"};
    for (int i = 0; i < 5; i++) {
        deportes[i] = deportesx[i];
    }
}

void animales(string animales[5]) {
    string animalesx[5] = {"perro", "gato", "tigre", "leon", "conejo"};
    for (int i = 0; i < 5; i++) {
        animales[i] = animalesx[i];
    }
}

void frutas(string frutas[5]) {
    string frutasx[5] = {"manzana", "pera", "uva", "cereza", "fresa"};
    for (int i = 0; i < 5; i++) {
        frutas[i] = frutasx[i];
    }
}

void paises (string paises[5]) {
    string paisesx[5] = {"peru", "ecuador", "colombia", "argentina", "chile"};
    for (int i = 0; i < 5; i++) {
        paises[i] = paisesx[i];
    }
}

