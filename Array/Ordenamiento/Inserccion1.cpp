#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void llenaVector(int v[], int n) {
    srand(time(NULL)); // función semilla para generar números aleatorios
    for (int i = 0; i < n; i++) {
        // Generar números aleatorios entre 1 y 20
        v[i] = rand() % 20 + 1;
        // Si prefieres que el usuario ingrese los valores manualmente, descomenta la siguiente línea:
        // cin >> v[i];
    }
}

void verVector(int v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << "\t";
    }
    cout << endl;
}

int ordenaInserccion(int v[], int n) {
    int contador = 0;
    int aux, j;
    for (int i = 1; i < n; i++) {
        aux = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > aux) {
            v[j + 1] = v[j];
            j--;
            contador++;  
        }
        v[j + 1] = aux;
    }
    return contador; 
}

int main() {
    int ne, comparaciones;
    cout << "Ingresa el numero de elementos del vector: ";
    cin >> ne;
    int vec[ne];
    llenaVector(vec, ne);
    cout << "Vector original: \n";
    verVector(vec, ne);
    comparaciones = ordenaInserccion(vec, ne);
    cout << "\nVector ordenado: ";
    verVector(vec, ne);
    cout << "\nEl numero de comparaciones = " << comparaciones << endl;
    return 0;
}
