#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "../../LIBRERIAS/Arrays.h"
using namespace std;
using namespace vectorn;



bool isBusquedaBinaria(int v[], int n, int elemento) {
    int arriba, abajo, centro;  
    abajo = 0;
    arriba = n - 1;
    while (arriba <= abajo) {
        centro = (abajo + arriba) / 2;
        if (v[centro] == elemento){
            return true;
        } else if (v[centro] < elemento){
            abajo = centro+1;
        } else {
            arriba = centro-1;
        }
    }
}

main ()
{
    int ne, dato;
    cout << "Numero de elemntos del array: ";
    cin >> ne;
    int vector[ne];
    llenarVector (vector,ne,20,50);
    cout<<"Datos originales\n";
    verVector (vector,ne);
    ordenaBurbujaV3 (vector,ne);
    cout<<"\nDatos ordenados\n";
    verVector (vector,ne);
    cout << "Ingrese el dato a buscar: ";
    cin >> dato;
    (isBusquedaBinaria(vector,ne, dato))? cout<<"Dato Encontrado": cout<<"El dato no existe";

}