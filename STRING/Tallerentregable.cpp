#include <iostream>
#include <string>
using namespace std;

void reemplazarPalabra(string &cadena, const string &buscar, const string &reemplazar) {
    size_t pos = 0;
    size_t len = cadena.length();
    
    while (pos < len) {

        pos = cadena.find(buscar, pos);
        if (pos == string::npos) break;
        
        bool esInicio = (pos == 0 || !isalpha(cadena[pos-1]));
        bool esFinal = (pos + buscar.length() == len || !isalpha(cadena[pos + buscar.length()]));
        
        if (esInicio && esFinal) {
            cadena.replace(pos, buscar.length(), reemplazar);
            pos += reemplazar.length();
            len = cadena.length(); 
        } else {
            // Si no es palabra completa, seguir buscando
            pos += 1;
        }
    }
}

int main() {
    string cadena, buscar, reemplazar;
    
    cout << "Ingrese la cadena principal: ";
    getline(cin, cadena);
    
    cout << "Ingrese la palabra que desea reemplazar: ";
    getline(cin, buscar);
    
    cout << "Ingrese la nueva palabra o frase: ";
    getline(cin, reemplazar);
    
    reemplazarPalabra(cadena, buscar, reemplazar); 
    
    return 0;
}

// Ejemplo de ejecución: