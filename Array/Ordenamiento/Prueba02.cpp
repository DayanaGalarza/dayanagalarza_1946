//
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void llenaVector(int v[], int n){
    for (int i = 0; i < n; i++){
        cin >> v[i];  
    }
}

int ordenaBurbujaV1(int v[], int n){
    int aux, contador = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1; j++){
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

int ordenaBurbujaV2(int v[], int n){
    int mejora = 1;
    int aux, contador = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - mejora; j++){
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

int ordenaBurbujaV3(int v[], int n){
    int mejora = 1;
    bool cambio = true;
    int aux, contador = 0;
    for (int i = 0; i < n && cambio; i++){
        cambio = false;
        for (int j = 0; j < n - mejora; j++){
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

void muestraVector(int v[], int n){
    for (int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void mejorAlgoritmo(int v1, int v2, int v3) {
    if (v1 <= v2 && v1 <= v3) {
        cout << "Burbuja V1 es la mas optima con " << v1 << " comparaciones." << endl;
    } else if (v2 <= v1 && v2 <= v3) {
        cout << "Burbuja V2 es la mas optima con " << v2 << " comparaciones." << endl;
    } else {
        cout << "Burbuja V3 es la mas optima con " << v3 << " comparaciones." << endl;
    }
}

int main(){
    int ne;
    cout << "Numero de elementos: ";
    cin >> ne;
    int vec[ne]; 
    cout << "Ingrese los elementos del vector:" << endl;
    llenaVector(vec, ne);  
    int vecV1[ne], vecV2[ne], vecV3[ne];
    for (int i = 0; i < ne; i++) {
        vecV1[i] = vec[i];
        vecV2[i] = vec[i];
        vecV3[i] = vec[i];
    }
    cout << "Vector original: ";
    muestraVector(vec, ne);
    int comparacionesV1 = ordenaBurbujaV1(vecV1, ne);
    cout << "El numero de comparaciones burbuja v1 = " << comparacionesV1 << endl;  
    int comparacionesV2 = ordenaBurbujaV2(vecV2, ne);
    cout << "El numero de comparaciones burbuja v2 = " << comparacionesV2 << endl;
    int comparacionesV3 = ordenaBurbujaV3(vecV3, ne);
    cout << "El numero de comparaciones burbuja v3 = " << comparacionesV3 << endl;
    mejorAlgoritmo(comparacionesV1, comparacionesV2, comparacionesV3);

    return 0;
}