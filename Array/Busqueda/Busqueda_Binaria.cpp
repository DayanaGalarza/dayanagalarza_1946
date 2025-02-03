#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../Ordenamiento/M_Seleccion.cpp"
using namespace std;

void llenaVector (int v[], int n){
    srand(time(NULL)); // función semilla para generar numeros
    for (int i=0; i<n; i++){
        v[i] = rand() % 10 + 1;
        //cin >> v[i];
    }
}

void llenaDato (int v[], int n){
   
}

void verDato (int v[], int n){
  
}


bool isBinario(int v[], int n, int elemento) {
    for (int arriba = 0, abajo = n - 1, centro; arriba <= abajo; ) {
        centro = (arriba + abajo) / 2;
        if (v[centro] == elemento) return true;
        (v[centro] < elemento) ? arriba = centro + 1 : abajo = centro - 1;
    }
    return false;
}

main ()
{
    int ne, dato;
    cout << "Numero de elemntos del array: ";
    cin >> ne;
    int vector[ne];
    llenaDato (vector,ne);
    cout << "Ingrese un numero para buscar: ";
    cin >> dato;
    ordenaSeleccion (vector,ne);
    (isBinario(vector,ne, dato))? cout<<"Dato Encontrado": cout<<"El dato no existe";

}