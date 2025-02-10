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
    // Comprobamos si es una letra en minúscula o mayúscula
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool esPalabraValida(char cad[]) {
    // Verificamos si la palabra está compuesta solo por letras
    for (int i = 0; cad[i] != '\0'; i++) {
        if (!esLetra(cad[i])) {
            return false;  // Si hay un carácter no alfabético, no es una palabra válida
        }
    }
    return true;
}

int contarPalabrasValidas(char cad[]) {
    int palabras = 0;
    bool palabra = false;
    char palabraActual[50];
    int j = 0;

    for (int i = 0; cad[i] != '\0'; i++) {
        if (esLetra(cad[i])) {
            if (!palabra) {
                palabra = true;
                j = 0;  // Empezamos a capturar una nueva palabra
            }
            palabraActual[j++] = cad[i];  // Añadimos la letra a la palabra
        } else {
            if (palabra) {
                palabraActual[j] = '\0';  // Terminamos la palabra actual
                if (esPalabraValida(palabraActual)) {
                    palabras++;  // Si la palabra es válida, contamos
                }
                palabra = false;
            }
        }
    }

    // Al final de la cadena, debemos verificar si hay una palabra por contar
    if (palabra) {
        palabraActual[j] = '\0';
        if (esPalabraValida(palabraActual)) {
            palabras++;
        }
    }

    return palabras;
}

int main() {
    char palabras[50];
    llenarCadena(palabras);
    cout << "La cadena ingresada es: " << palabras << endl;
    cout << "La longitud de la cadena es: " << longitudCadena(palabras) << endl;
    cout << "El numero de palabras validas en la cadena es: " << contarPalabrasValidas(palabras) << endl;
    return 0;
}
