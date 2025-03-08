#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    ifstream archivoEntrada;
    //Abrir el archivo
    archivoEntrada.open("ejemplo.txt");
    //Verificar si se pudo abrir el archivo  y leerlo si es posible
    if(archivoEntrada.is_open()){
        string linea;
        //leer el archivo linea por linea
        while(getline(archivoEntrada, linea)){
            cout << "Leido" << linea << endl;
        }
        //Cerrar el archivo
        archivoEntrada.close();
    }
    else {
        cout << "No se puede abrir el archivo" << endl;
    }
    return 0;
}