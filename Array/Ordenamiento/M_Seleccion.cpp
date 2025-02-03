#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void llenaVector (int v[], int n){
    srand(time(NULL)); // función semilla para generar numeros
    for (int i=0; i<n; i++){
        v[i] = rand() % 20 + 1;
        //cin >> v[i];
    }
}

void verVector (int v[], int n){
    for (int i=0; i<n; i++){
        cout << v[i] << "\t";
    }
}
int ordenaSeleccion (int v[], int n){
    int contador=0, aux;
    bool cambios = true;
    for (int i=0; i<n-1 && cambios; i++){
        cambios = false;
        for (int j=i+1; j<n; j++){
            contador ++;
            if (v[i]>v[j]){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                cambios = true;
            }
        }
    }
    return contador; // Devuelve el número de comparaciones realizadas en el algoritmo.
}
main(){
    int ne, comparaciones;
    cout << " Ingresa el numero de elementos del vector: ";
    cin >> ne;
    int vec[ne]; 
    llenaVector (vec, ne);
    cout << " Vector original: \n";
    verVector (vec, ne);
    comparaciones= ordenaSeleccion(vec, ne);
    cout <<"\nVector ordenado :"; 
    verVector (vec, ne);  
    cout << "\nEl numero de comparaciones = " << comparaciones;
 }