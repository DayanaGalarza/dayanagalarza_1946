#include <iostream>
using namespace std;

// Función para asignar deportes
void deportes(string deportes[5]) {
    string deportesx[5] = {"Futbol", "Tenis", "Baloncesto", "Voley", "Natacion"};
    for (int i = 0; i < 5; i++) {
        deportes[i] = deportesx[i];
    }
}

// Función para asignar animales
void animales(string animales[5]) {
    string animalesx[5] = {"Perro", "Gato", "Tigre", "Leon", "Conejo"};
    for (int i = 0; i < 5; i++) {
        animales[i] = animalesx[i];
    }
}

// Función para asignar frutas
void frutas(string frutas[5]) {
    string frutasx[5] = {"Manzana", "Pera", "Uva", "Cereza", "Fresa"};
    for (int i = 0; i < 5; i++) {
        frutas[i] = frutasx[i];
    }
}

