#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../Ordenamiento/M_Seleccion.cpp"
using namespace std;

void llenaVector(int v[], int n) {
    srand(time(NULL)); // función semilla para generar numeros
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 10 + 1;
    }
}

void llenaDato(int v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el elemento " << i << ": ";
        cin >> v[i];
    }
}

void verDato(int v[], int n) {
    cout << "Elementos del vector: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

bool isBinario(int v[], int n, int elemento) {
    int arriba = 0, abajo = n - 1;
    while (arriba <= abajo) {
        int centro = (arriba + abajo) / 2;
        if (v[centro] == elemento) {
            return true;
        } else if (v[centro] < elemento) {
            arriba = centro + 1;
        } else {
            abajo = centro - 1;
        }
    }
    return false;
}

int main() {
    int ne, dato;
    cout << "Numero de elemntos del array: ";
    cin >> ne;
    int vector[ne];
    llenaDato(vector, ne);
    cout << "Ingrese un numero para buscar: ";
    cin >> dato;
    ordenaSeleccion(vector, ne);
    verDato(vector, ne);
    (isBinario(vector, ne, dato)) ? cout << "Dato Encontrado" : cout << "El dato no existe";
    return 0;
}