#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void llenaVector(int v[], int n){
    srand(time(NULL)); // función semilla para generar numeros
    for (int i=0; i<n; i++){
        v[i] = rand() % 10 + 1;
    }
}

void llenaDato(int v[], int n){
    cout << "Ingrese " << n << " elementos para el vector:" << endl;
    for(int i = 0; i < n; i++){
        cout << "Elemento " << i + 1 << ": ";
        cin >> v[i];
    }
}

void verDato(int v[], int n){
    cout << "Elementos del vector: ";
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void ordenaSeleccion(int v[], int n){
    int min, temp;
    for(int i = 0; i < n - 1; i++){
        min = i;
        for(int j = i + 1; j < n; j++){
            if(v[j] < v[min]){
                min = j;
            }
        }
        if(min != i){
            temp = v[i];
            v[i] = v[min];
            v[min] = temp;
        }
    }
}

bool isBinario(int v[], int n, int elemento) {
    for (int arriba = 0, abajo = n - 1, centro; arriba <= abajo; ) {
        centro = (arriba + abajo) / 2;
        if (v[centro] == elemento) return true;
        (v[centro] < elemento) ? arriba = centro + 1 : abajo = centro - 1;
    }
    return false;
}

main(){
    int ne, dato;
    cout << "Numero de elementos del array: ";
    cin >> ne;
    int vector[ne];
    
    // Generamos números aleatorios
    llenaVector(vector, ne);
    
    cout << "\nVector original con numeros aleatorios:" << endl;
    verDato(vector, ne);
    
    cout << "\nIngrese un numero para buscar (entre 1 y 10): ";
    cin >> dato;
    
    cout << "\nVector ordenado:" << endl;
    ordenaSeleccion(vector, ne);
    verDato(vector, ne);
    
    cout << "\nResultado de la busqueda: ";
    (isBinario(vector, ne, dato))? cout << "Dato Encontrado" : cout << "El dato no existe";
    cout << endl;
    
    return 0;
}