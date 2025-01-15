#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    int op;
    do {
        cout << "Menu de opciones" << endl;
        cout << "1. Abundantes" << endl;
        cout << "2. Deficientes" << endl;
        cout << "3. Amigos" << endl;
        cout << "4. Salir" << endl;
        cout << "Escoja una opcion: ";
        cin >> op;

        // Limpiar la pantalla al volver al menú
        system("cls");

        switch (op) {
            case 1:
                cout << "Abundantes" << endl;
                break;
            case 2:
                cout << "Deficientes" << endl;
                break;
            case 3:
                cout << "Amigos" << endl;
                break;
            case 4:
                cout << "Saliendo del sistema" << endl;
                break;
            default:
                cout << "Opcion no valida, intente nuevamente." << endl;
        }

        if (op != 4) {
            system("pause");
            system("cls"); // Limpiar la pantalla después de mostrar la opción seleccionada
        }

    } while (op != 4); // El ciclo sigue hasta que se elige la opción 4 (Salir)

    return 0;
}
