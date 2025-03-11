#include <iostream>
using namespace std;

int separaCifras(int num, int &digito) {
    int suma = 0, contador = 0;
    while (num > 0) {
        if (contador == 0)
            digito = num % 10;  // Guarda el último dígito
        suma += num % 10;  // Suma el dígito actual
        num /= 10;  // Elimina el último dígito del número
        contador++;
    }
    return suma;  // Retorna la suma de las cifras
}

int main() {
    int num, digito, suma;
    cout << "Introduce un número entero: ";
    cin >> num;
    suma = separaCifras(num, digito);
    cout << "La suma de las cifras de " << num << " es: " << suma << endl;
    (suma % digito == 0) ? cout << "La suma de las cifras es múltiplo del último dígito." << endl : cout << "La suma de las cifras no es múltiplo del último dígito." << endl;
}