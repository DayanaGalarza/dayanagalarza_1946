#include <iostream>
using namespace std;

string identificarTipoCadena(const string& cadena) {
    bool esNumerica = true;
    bool esAlfanumerica = true;
    bool esAlfabetica = true;

    for (char c : cadena) {
        // Verificar si el carácter es un dígito numérico (ASCII 48-57)
        if (!(c >= '0' && c <= '9')) {
            esNumerica = false; 
        }
        
        // Verificar si el carácter es alfabético (letras A-Z, a-z)
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
            esAlfabetica = false;  
        }
        
        // Verificar si el carácter es alfanumérico (letras o dígitos)
        if (!( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))) {
            esAlfanumerica = false;  
        }
    }
    
    // Determinar el tipo de la cadena
    if (esNumerica) {
        return "Numerica";
    } else if (esAlfabetica) {
        return "Alfabetica"; 
    } else if (esAlfanumerica) {
        return "Alfanumerica";
    } else {
        return "Desconocido";
    }
}

int main() {
    string cadena;

    cout << "Ingresa una cadena de texto: ";
    cin >> cadena;  

    cout << "La cadena '" << cadena << "' es de tipo: " << identificarTipoCadena(cadena) << endl;

}
