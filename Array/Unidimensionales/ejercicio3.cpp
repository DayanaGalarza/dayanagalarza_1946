#include <iostream>
#include <cstdlib>  // Para usar rand() y srand()
#include <ctime>
#define MAX 50
using namespace std;

void llenarMatriz(int matriz[][MAX], int filas, int columnas) {
    srand(time(0)); 
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 11 + 10; 
        }
    }
}   

void imprimirMatriz(int matriz[][MAX], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Función para calcular la suma de la diagonal principal
int sumaDiagonalPrincipal(int matriz[][MAX], int filas) {
    int suma = 0;
    for (int i = 0; i < filas; i++) {
        suma += matriz[i][i];
    }
    return suma;
}

// Función para calcular la suma de la diagonal secundaria
int sumaDiagonalSecundaria(int matriz[][MAX], int filas) {
    int suma = 0;
    for (int i = 0; i < filas; i++) {
        suma += matriz[i][filas - 1 - i];
    }
    return suma;
}

// Función para determinar qué diagonal tiene la mayor suma
void compararDiagonales(int sumaPrincipal, int sumaSecundaria) {
    if (sumaPrincipal > sumaSecundaria) {
        cout << "La diagonal principal tiene la mayor suma: " << sumaPrincipal << endl;
    } else if (sumaSecundaria > sumaPrincipal) {
        cout << "La diagonal secundaria tiene la mayor suma: " << sumaSecundaria << endl;
    } else {
        cout << "Ambas diagonales tienen la misma suma: " << sumaPrincipal << endl;
    }
}

void mostrarDiagonalesX(int matriz[][MAX], int filas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < filas; j++) {
            // Imprimir las diagonales principales y secundarias
            if (i == j || j == (filas - 1 - i)) {
                cout << matriz[i][j] << " ";
            } else {
                cout << "   "; 
            }
        }
        cout << endl;
    }
}

int main() {
    int matriz[MAX][MAX];
    int filas;
    cout << "Ingrese el numero de filas y columnas (maximo " << MAX << "): ";
    cin >> filas;
    if (filas <= 0 || filas > MAX) {
        cout << "Error: El numero debe estar entre 1 y " << MAX << endl;
        return 1;
    }
    llenarMatriz(matriz, filas, filas);
    cout << "\nMatriz original:\n";
    imprimirMatriz(matriz, filas, filas);

    // Calcular las sumas de las diagonales
    int sumaPrincipal = sumaDiagonalPrincipal(matriz, filas);
    int sumaSecundaria = sumaDiagonalSecundaria(matriz, filas);

    cout << "\nSuma de la diagonal principal: " << sumaPrincipal << endl;
    cout << "Suma de la diagonal secundaria: " << sumaSecundaria << endl;
    cout << endl;

    // Mostrar cuál diagonal tiene la mayor suma
    compararDiagonales(sumaPrincipal, sumaSecundaria);

    // Mostrar la matriz con solo las diagonales
    cout << "\nMatriz con las diagonales:\n";
    mostrarDiagonalesX(matriz, filas);

}