#include <iostream>
using namespace std;
bool isEncontrado (int v[], int n, int elemento){
    int i;
    //bool entontrado = false;
    for (i=0; i<n; i++)
    {
        if (v[i] == elemento){
            /*entontrado = true; 
            break;*/
            return true; 
        }
    }
    return false;
}

void llenaDatos (int v[], int n){
    for (int i=0; i<n; i++){
        v[i] = (i+1)*3;
    }
}

void verElemntos (int v[], int n){
    for (int i=0; i<n; i++){
        cout << v[i] << "\t";
    }
}

main ()
{
    int vector[5], dato;
    llenaDatos(vector, 5);
    cout << "Ingresa el dato a buscar: ";
    cin >> dato;
    (isEncontrado(vector,5,dato))? cout<<"El elemento esta en el array": cout<<"El elemento no existe";

}