#include <iostream>
#include <stdlib.h> // libreria para el uso de rand
#include <time.h> // libreria para el uso de time

using namespace std;
void llenaDatos (int v [], int ne){
    srand(time(NULL)); // funcion semilla para generar numeros
    for (int i = 0; i < ne; i++){
        v[i] = rand() % 20 + 1;
    }
}
void verDatos (int v [], int ne){
    cout <<"Los elementos del vector son: " << endl;
    for (int i = 0; i < ne; i++){
        cout << v[i] << " ";
    }  
}
float sumaPrometioCifras (int v [], int ne){
    int suma=0;
    for (int i = 0; i < ne; i++){
        suma += v[i];
    }
    return (float)suma / ne;
}

int contarDebajoPromedio (int v [], int ne, float promedio){
    int contar = 0 ;
    for (int i = 0; i < ne; i++){
        if(v[i] < promedio){
            contar++;
        }
    }
    return contar;
}
void guardaElementosMenores (int v [], int ne, float promedio, int lista[]){
    int j = 0;
    for (int i = 0; i < ne; i++){
        if(v[i] < promedio){
            lista[j] = v[i];
            j++;
        }
    }
}
main (){
    int ne,menores;
    float promedioNumeros;
    cout<<"Cuantos elementos tiene el vector?: ";
    cin>>ne;
    int vector [ne];
    llenaDatos (vector, ne);
    verDatos (vector, ne);
    promedioNumeros = sumaPrometioCifras (vector, ne);
    cout << "El promedio de los datos generados es= " << promedioNumeros << endl;
    menores = contarDebajoPromedio (vector, ne, promedioNumeros);
    cout << "La candidad de elementos debajo del promedio son: " << menores<< endl;
    int listaMenores [menores]; 
    guardaElementosMenores (vector, ne, promedioNumeros, listaMenores);
    verDatos (listaMenores, menores);
}