#include <iostream>
#include <vector>
using namespace std;

void cambiar_elemento(vector <int> & num){
    num[0] = 100;
}

main(){
    vector <int> datos, datos1;
    int numeros[10], valores[10];
    vector <float> notas(3,4.5); //Inicializa con 3 elementos de 4.5
    datos.push_back(10);
    datos.push_back(20);
    datos.push_back(30);
    datos.push_back(40);
    datos.push_back(50);
    datos1=datos;

    for (int i = 0; i < datos.size();i++){
        cout << datos[i] << " ";
    }
    cout<<endl;
    for (auto x: datos){
        cout << x << " ";
    }
    cout<<"\n";
    for (auto y: notas){
        cout << y << " ";
    }
    cout<<"\ndatos1\n";
    for(auto x: datos1){
        cout << x << " ";
    }
    datos.erase(datos.begin()+2, datos.begin()+4);
    cout<<"\nNuevos elementos de datos"<< endl;
    for (auto x: datos){
        cout << x << " ";
    }
    datos.erase(datos.begin()+1, datos.begin()+2 );
    cout<<"\nNuevos elementos de datos"<< endl;
    for (auto x: datos){
        cout << x << " ";
    }
    cout<<"Insertando elemntos entre elemntos"<< endl;
    datos.insert(datos.begin()+1,80);
    cout<<"\nNuevos elementos de datos"<< endl;
    for (auto x: datos){
        cout << x << " ";
    }
    cout<<"Insertando valores en una posicion n veces"<<endl;
    datos.insert(datos.begin()+2,3,23);
    cout<<"\nNuevos elementos de datos"<< endl;
    for (auto x: datos){
        cout << x << " ";
    }

    cambiar_elemento(datos);
    cout<<"\nNuevos elementos de datos despues de llamar a la funcion"<< endl;
    for (auto x: datos){
        cout << x << " ";
    }

    datos.pop_back();
    cout<<"\nNuevos elementos de datos despues de eliminar el ultimo"<< endl;
    for (auto x: datos){
        cout << x << " ";
    }
    cout<<boolalpha << endl;
    cout<<datos.empty();
}