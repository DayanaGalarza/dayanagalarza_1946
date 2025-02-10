#include <iostream>
#include <cstring>
using namespace std;

void llenarCadena(char cad[], int n = 50) {
    cout << "Ingresa una Cadena de caracteres: ";
    cin.getline(cad, n);
    cin.clear();
}

int longitudCadena(char cad[]) {
    int contador = 0;
    for (int i = 0; cad[i] != '\0'; i++)
        contador++;
    return contador;
}

bool esLetra(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool esVocal(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool esPalabraValida(char palabra[]) {
    int longitud = strlen(palabra);
    
    // La palabra debe tener entre 1 y 15 caracteres
    if (longitud < 1 || longitud > 15) {
        return false;
    }
    
    // Debe tener al menos una vocal
    bool tieneVocal = false;
    int consonantesSeguidasDespuesDeVocal = 0;
    
    for (int i = 0; palabra[i] != '\0'; i++) {
        // Si no es letra, la palabra no es válida
        if (!esLetra(palabra[i])) {
            return false;
        }
        
        if (esVocal(palabra[i])) {
            tieneVocal = true;
            consonantesSeguidasDespuesDeVocal = 0;
        } else {
            consonantesSeguidasDespuesDeVocal++;
            // Si hay más de 4 consonantes seguidas, probablemente no es una palabra real
            if (consonantesSeguidasDespuesDeVocal > 4) {
                return false;
            }
        }
    }
    
    return tieneVocal;
}

int contarPalabrasValidas(char cad[]) {
    char palabraTemp[50];
    int indicePalabra = 0;
    int totalPalabras = 0;
    
    for (int i = 0; cad[i] != '\0'; i++) {
        if (esLetra(cad[i])) {
            palabraTemp[indicePalabra++] = cad[i];
        } else if (indicePalabra > 0) {
            palabraTemp[indicePalabra] = '\0';
            if (esPalabraValida(palabraTemp)) {
                totalPalabras++;
            }
            indicePalabra = 0;
        }
    }
    
    // Verificar la última palabra si existe
    if (indicePalabra > 0) {
        palabraTemp[indicePalabra] = '\0';
        if (esPalabraValida(palabraTemp)) {
            totalPalabras++;
        }
    }
    
    return totalPalabras;
}

int main() {
    char cadena[50];
    llenarCadena(cadena);
    cout << "La cadena ingresada es: " << cadena << endl;
    cout << "La longitud de la cadena es: " << longitudCadena(cadena) << endl;
    cout << "El numero de palabras validas es: " << contarPalabrasValidas(cadena) << endl;
    return 0;
}