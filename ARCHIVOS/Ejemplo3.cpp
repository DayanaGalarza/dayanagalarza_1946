#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream archivoSalida;
    archivoSalida.open("ejemplo.txt", ios::app);
    if (archivoSalida.is_open()) {
        archivoSalida << "Linea agregada al final. " << endl;
        archivoSalida << "Otra linea mas. " << endl;
        archivoSalida.close();
        cout << "Texto agrgado exitosamente." << endl;
    }
    else{
        cout << "Error al abrir el archivo." << endl;
    }
    return 0;
}