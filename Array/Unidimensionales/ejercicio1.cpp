#include <iostream>
using namespace std;
void llenaVector (int v[], int tamanio){
    for (int i = 0; i < tamanio; i++){
    cout << "Ingrese un numero: " << i+1 <<": "; 
    cin >> v[i];
    }
}

void verVector (int v[], int tamanio){
    for (int i =0; i < tamanio; i++){
        cout << "Elemento " << i+1 << " del vector es: " << v[i] << endl; 
    }
}
main ()
{
    int ne;
    cout<<"Cuantos elementos tiene el vector?: ";
    cin>>ne;
    int vector[ne];
    llenaVector(vector, ne);
    verVector (vector, ne);

}