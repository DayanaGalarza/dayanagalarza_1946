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

// Función para convertir string a minúsculas
string convertirAMinusculas(string palabra) {
    string resultado = palabra;
    for(int i = 0; i < palabra.length(); i++) {
        resultado[i] = tolower(palabra[i]);
    }
    return resultado;
}

string palabraAleatoria(string palabras[]) {
    srand(time(NULL));
    int numero = rand() % 5;
    return convertirAMinusculas(palabras[numero]); // Convertir a minúsculas al seleccionar
}

int opciones() {
    int op;
    do {
        cout << "1. Deportes" << endl;
        cout << "2. Animales" << endl;
        cout << "3. Frutas" << endl;
        cout << "Ingrese opcion (1-3): ";
        cin >> op;
        
        if(op < 1 || op > 3) {
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while(op < 1 || op > 3);
    return op;
}

int main() {
    string palabras[5], palabraSeleccionada;
    int op, intentosFallidos = 0;
    char letra;
    bool letraEncontrada;
    string letrasUsadas = "";

    cout << "Juego del Ahorcado" << endl;
    cout << "-----------------" << endl;
    cout << "Elige una categoria" << endl;
    
    op = opciones();
    (op == 1) ? deportes(palabras) : (op == 2) ? animales(palabras) : frutas(palabras);
    
    palabraSeleccionada = palabraAleatoria(palabras);
    string palabraMostrar(palabraSeleccionada.length(), '_');
    
    while (intentosFallidos < 6 && palabraMostrar != palabraSeleccionada) {
        system("cls"); // Usar "clear" en Linux/Mac
        
        // Mostrar estado actual
        cout << "\nPalabra a adivinar: ";
        for (int i = 0; i < palabraMostrar.length(); i++) {
            cout << palabraMostrar[i] << " ";
        }
        
        cout << "\n\nLetras usadas: " << letrasUsadas << endl;
        mostrarMuneco(intentosFallidos);
        cout << "\nIntentos fallidos: " << intentosFallidos << "/6" << endl;
        
        // Pedir letra al usuario
        cout << "\nIngrese una letra: ";
        cin >> letra;
        letra = tolower(letra); // Convertir entrada a minúscula
        
        // Verificar si la letra ya fue usada
        if(letrasUsadas.find(letra) != string::npos) {
            cout << "\n¡Ya usaste esa letra! Intenta con otra." << endl;
            system("pause");
            continue;
        }
        
        // Agregar letra a las usadas
        letrasUsadas += letra;
        letrasUsadas += " ";
        
        // Verificar si la letra está en la palabra
        letraEncontrada = false;
        for (int i = 0; i < palabraSeleccionada.length(); i++) {
            if (palabraSeleccionada[i] == letra) {
                palabraMostrar[i] = letra;
                letraEncontrada = true;
            }
        }
        
        if (!letraEncontrada) {
            intentosFallidos++;
            cout << "\n¡Letra incorrecta!" << endl;
            system("pause");
        }
    }
    
    // Mostrar resultado final
    system("cls");
    mostrarMuneco(intentosFallidos);
    
    if (intentosFallidos < 6) {
        cout << "\n¡Felicidades! Has ganado. La palabra era: " << palabraSeleccionada << endl;
    } else {
        cout << "\n¡Has perdido! La palabra era: " << palabraSeleccionada << endl;
    }
    
    return 0;
}