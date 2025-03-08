#include <iostream>
#include <fstream>
using namespace std;
int main(){
    //crea un objeto para escribir en el archivo
    ofstream archivoSalida;
    //abre el archivo en modo escritura (si no existe, lo crea)
    archivoSalida.open("ejemplo.doc");
    //comprueba si se pudo abrir el archivo para escribir
    if (archivoSalida.is_open()) {
        //escribe texto en el archivo
        archivoSalida << "!Hola mundo!\n";
        archivoSalida << "Esto es una prueba.\n";
        archivoSalida << "Linea 3.";
        //cerrar el archivo
        archivoSalida.close();
        cout << "Texto escrito en el archivo con exito.\n";
    }
    else {
        cout << "No se puede abrir el archivo.\n";
    }
    return 0; 
}