#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../LIBRERIAS/Arrays.h"

using namespace std;

int main() {
    int min, max, minumero, numgenerado;
    int intentos = 3;
    

    cout << "Ingresa el valor minimo del rango: ";
    cin >> min;
    cout << "Ingresa el valor maximo del rango: ";
    cin >> max;
    srand(time(0));
    numgenerado = rand() % (max - min + 1) + min;

    cout << "He generado un numero aleatorio entre " << min << " y " << max << ". \nTienes " << intentos << " intentos para adivinarlo." << endl;


    for (int i = 1; i <= intentos; i++) {
        cout << "Intento " << i << ": Ingresa el numero que creeas que es: ";
        cin >> minumero;

        if (minumero < numgenerado) {
            cout << "El numero es mayor. Intenta de nuevo." << endl;
        } else if (minumero > numgenerado) {
            cout << "El numero es menor. Intenta de nuevo." << endl;
        } else {
            cout << "Felicidades. Adivinaste el numero correctamente." << endl;
            return 0; 
        }
    }

    cout << "Lo siento, no adivinaste el número. El número correcto era " << numgenerado << "." << endl;

    return 0;
}
