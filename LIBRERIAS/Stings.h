#include <iostream>
using namespace std;
void reemplazar(string &cadena){
    string cadena2, cadena3;
    int pos,nencontrado=0;
    char respuesta;
    cout << "Ingrese cadena objetivo: ";
    getline(cin, cadena2);
    cout << "Ingrese cadena para reemplazar: ";
    getline(cin, cadena3);
    pos = cadena.find(cadena2);
    while (pos != string::npos) {
        nencontrado++;
        cout<<"Lo buscado esta en la posicion "<<nencontrado<<"  Desea Reemplazarlo?<<s/n: ";
        respuesta = cin.get();
        cin.ignore();  
        if(respuesta == 's' || respuesta == 'S'){
            cadena.replace(pos, cadena2.size(), cadena3);      
        }
        pos = cadena.find(cadena2, pos + cadena3.size());
    }  

}