#include <iostream>
#include <string>
using namespace std;

void reemplazarPalabra(string &cadena, const string &buscar, const string &reemplazar) {
    size_t pos = cadena.find(buscar);
    if (pos != string::npos) {
        cadena.replace(pos, buscar.length(), reemplazar);
    } else {
        cout << "No se encontró la palabra o frase a reemplazar." << endl;
    }
}

int main() 
{
    string cadena, buscar, reemplazar;
    cout << "Ingrese la cadena principal: ";
    getline(cin, cadena);
    cout << "Ingrese la palabra que desea reemplazar: ";
    getline(cin, buscar);
    cout << "Ingrese la nueva palabra o frase: ";
    getline(cin, reemplazar);
    reemplazarPalabra(cadena, buscar, reemplazar);
    cout << "Cadena modificada: " << cadena << endl;

}
