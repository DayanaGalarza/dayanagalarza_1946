#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    fstream archivo;
    string frase, nombreArchivo;
    cout <<"Ingrse el nombre  archivo con extension: ";
    cin >> nombreArchivo;

    cout << "Escribe una frase para agregar al archvo: ";
    cin.ignore(); 
    getline(cin, frase);
    
    archivo.open(nombreArchivo.c_str(), ios::out | ios::app);
    if (archivo.is_open()) {
        archivo << frase << endl;
        cout << "La frase se agrego correctamente al archivo." << endl;
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }


}