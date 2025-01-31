#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void llenaVector (int v[], int n){
    srand(time(NULL)); // función semilla para generar numeros8
    for (int i=0; i<n; i++){
        //v[i] = rand() % 20 + 1;
        cin >> v[i];
    }
}

int ordenaBurbujaV1 (int v[], int n){
    int aux, contador=0;
    for (int i=0; i<n ; i++){
        for (int j=0; j<n-1; j++){
            contador++;
            if (v[j] > v[j + 1]){
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
    return contador;
}

int ordenaBurbujaV2 (int v[], int n){
    int mejora=1;
    int aux, contador=0;
    for (int i=0; i<n ; i++){
        for (int j=0; j<n-mejora; j++){
            contador++;
            if (v[j] > v[j + 1]){
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
        mejora++;
    }
    return contador;
}

int ordenaBurbujaV3 (int v[], int n){
    int mejora=1;
    bool cambio=true;
    int aux, contador=0;
    for (int i=0; i<n && cambio; i++){
        cambio= false;
        for (int j=0; j<n-mejora; j++){
            contador++;
            if (v[j] > v[j + 1]){
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                cambio = true;
            }
        }
        mejora++;
    }
    return contador;
}

void muestraVector (int v[], int n){
    for (int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
}

main (){
    int ne;
    cout << "Numero de elementos: ";
    cin >> ne;
    int vec [ne];
    llenaVector (vec,ne);
    cout << "Vector original: ";
    muestraVector (vec, ne);
    cout << endl;
    cout << "El numero de comparaciones burbuja v1 = " << ordenaBurbujaV1 (vec, ne) <<endl;
    cout << "El numero de comparaciones burbuja v2 = " << ordenaBurbujaV2 (vec, ne) <<endl;
    cout << "El numero de comparaciones burbuja v3 = " << ordenaBurbujaV3 (vec, ne) <<endl;
    ordenaBurbujaV1 (vec, ne);
    cout << "\nVector ordenado: "<<endl;
    muestraVector (vec, ne);
}