#include <iostream>
#include <cstring>
using namespace std;

// Function to input a string and capitalize the first letter
void ingreseCadena(char* cadena, int longitud) {
    cout << "Ingrese una cadena de caracteres: ";
    cin.getline(cadena, longitud);
    
    // Capitalize first character (if it's a lowercase letter)
    if (cadena[0] >= 'a' && cadena[0] <= 'z') {
        cadena[0] = cadena[0] - 32;
    }
}

// Function to calculate the length of a string
int longitudCadena(char cadena[]) {
    int longitud = 0;
    while (cadena[longitud] != '\0') {
        longitud++;
    }
    return longitud;
}

// Function to display the string
void muestraCadena(char cadena[]) {
    ingreseCadena(cadena, 100);
    cout << "La cadena ingresada es: " << cadena << endl;
}

// Main function
int main() {
    char cadena[100];
    muestraCadena(cadena);
    cout << "La longitud de la cadena es: " << longitudCadena(cadena) << endl;
    
    return 0;
}