#include <iostream>
using namespace std;

const char* clasificar(int valor) {
    int categoria = (valor - 1) / 5; 
    const char* categorias[] = {
        "Deficiente",  // 0 para valores 1-5
        "Regular",     // 1 para valores 6-10
        "Bueno",       // 2 para valores 11-15
        "Muy Bueno",   // 3 para valores 16-18
        "Excelente"    // 4 para valores 19-20
    };

    if (valor < 1 || valor > 20) {
        return "Valor fuera de rango"; 
    }

    if (valor > 18) {
        return categorias[4];
    }

    return categorias[categoria]; 
}

int main() {
    int valor;
    cout << "Introduce un valor entre 1 y 20: ";
    cin >> valor;
    cout << clasificar(valor) << endl;
}