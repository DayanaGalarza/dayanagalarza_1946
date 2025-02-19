#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "../LIBRERIAS/Ahorcado.h"
using namespace std;

void mostrarMuneco(int intentos) {
    switch(intentos) {
        case 0:
            cout << "\n  -----" << endl;
            cout << "  |   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << " -----" << endl;
            break;
        case 1:
            cout << "\n  -----" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << " -----" << endl;
            break;
        case 2:
            cout << "\n  -----" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << "  |   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << " -----" << endl;
            break;
        case 3:
            cout << "\n  -----" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << " -----" << endl;
            break;
        case 4:
            cout << "\n  -----" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << " -----" << endl;
            break;
        case 5:
            cout << "\n  -----" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << " /    |" << endl;
            cout << "      |" << endl;
            cout << " -----" << endl;
            break;
        case 6:
            cout << "\n  -----" << endl;
            cout << "  |   |" << endl;
            cout << "  O   |" << endl;
            cout << " /|\\  |" << endl;
            cout << " / \\  |" << endl;
            cout << "      |" << endl;
            cout << " -----" << endl;
            break;
    }
}

string palabraAleatoria(string palabras[]) {
    srand(time(NULL));
    int numero = rand() % 5;
    return palabras[numero]; 
}

int opciones() {
    int op;
    do {
        cout << "1. Deportes" << endl;
        cout << "2. Animales" << endl;
        cout << "3. Frutas" << endl;
        cout << "4. Paises" << endl;
        cout << "Ingrese opcion (1-4): ";
        cin >> op;
        
        if(op < 1 || op > 4) {
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while(op < 1 || op > 4);
    return op;
}

int main() {
    string palabras[5], palabraSeleccionada;
    int op, intentosFallidos = 0;
    char letra;
    bool letraEncontrada;

    cout << "Juego del Ahorcado" << endl;
    cout << "-----------------" << endl;
    cout << "Elige una categoria" << endl;
    
    op = opciones();
    (op == 1) ? deportes(palabras) : (op == 2) ? animales(palabras) : (op == 2) ? frutas(palabras) : paises(palabras);
    
    palabraSeleccionada = palabraAleatoria(palabras);
    string palabraMostrar(palabraSeleccionada.length(), '_');
    
    while (intentosFallidos < 6 && palabraMostrar != palabraSeleccionada) {
        system("cls"); 
        
        cout << "\nPalabra a adivinar: ";
        for (int i = 0; i < palabraMostrar.length(); i++) {
            cout << palabraMostrar[i] << " ";
        }
        
        mostrarMuneco(intentosFallidos);
        cout << "\nIntentos fallidos: " << intentosFallidos << "/6" << endl;
        cout << "\nIngrese una letra: ";
        cin >> letra;

        letraEncontrada = false;
        for (int i = 0; i < palabraSeleccionada.length(); i++) {
            if (palabraSeleccionada[i] == letra) {
                palabraMostrar[i] = letra;
                letraEncontrada = true;
            }
        }
        
        if (!letraEncontrada) {
            intentosFallidos++;
            cout << "\nLetra incorrecta" << endl;
            system("pause");
        }
    }

    system("cls");
    mostrarMuneco(intentosFallidos);
    
    if (intentosFallidos < 6) {
        cout << "\nFelicidades. Has ganado. La palabra era: " << palabraSeleccionada << endl;
    } else {
        cout << "\nHas perdido. La palabra era: " << palabraSeleccionada << endl;
    }

}
