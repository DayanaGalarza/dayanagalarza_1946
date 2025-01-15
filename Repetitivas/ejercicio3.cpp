#include <iostream>
using namespace std;

int main() {
    int limiteInferior, limiteSuperior;

    // Pedir límites del intervalo
    do {
        cout << "Introduce el límite inferior del intervalo: ";
        cin >> limiteInferior;
        cout << "Introduce el límite superior del intervalo: ";
        cin >> limiteSuperior;
        if (limiteInferior >=limiteSuperior) {
            cout << "El límite inferior debe ser menor que el límite superior. Inténtalo de nuevo.\n";
        }
    } while (limiteInferior >= limiteSuperior);

    int suma_dentro = 0, fuera_intervalo = 0;
    bool igual_a_limite = false;
    int numero;

    cout << "\nIntroduce números (0 para terminar):\n";

    while (true) {
        cout << "Número: ";
        cin >> numero;

        if (numero == 0) break; // Terminar el programa

        if (numero > limiteInferior && numero < limiteSuperior) {
            suma_dentro += numero;
        } else {
            fuera_intervalo++;
        }

        if (numero == limiteInferior || numero == limiteSuperior) {
            igual_a_limite = true;
        }
    }

    // Resultados
    cout << "\nResultados:\n";
    cout << "Suma de los números dentro del intervalo abierto (" 
         << limiteInferior << ", " << limiteSuperior << "): " << suma_dentro << endl;
    cout << "Cantidad de números fuera del intervalo: " << fuera_intervalo << endl;
    cout << "¿Se ha introducido algún número igual a los límites? " 
         << (igual_a_limite ? "Sí" : "No") << endl;

}
