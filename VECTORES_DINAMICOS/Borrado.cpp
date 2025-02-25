#include <iostream>
#include <vector>
using namespace std;

main(){
    vector<int> numeros(10);
    for (int i = 0; i <10; i++){
        numeros.push_back(i+1);
    }
    cout<<"Elemntos del vector: "<<endl;
    for (auto x: numeros){
        cout<<x<<" ";
    }
    cout<<"\nTamanio del vector: "<<numeros.size()<<endl;
    numeros.erase(numeros.begin()+3, numeros.begin()+6);
    for (auto x: numeros){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"Tamanio del vector: "<<numeros.size()<<endl;
}


/*hacer un listado con id nombre nota 1 nota 2 promedio sacar media aritmetica (promedio total) desviacion estandar y z estandarizada categoria A z>1 B z=0,1 C 0 -1 D -1...
hacer un menu donde tenga 
1.listado de resultado 
2.añadir estudiante 
3.elimina estudiante
4.salir*/