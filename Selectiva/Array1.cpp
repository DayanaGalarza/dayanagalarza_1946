#include <iostream>
#include <cstring> // Para manejar cadenas

using namespace std;

const char* tipo_cadena(const char* cadena) {
    int i = 0;
    bool es_numero = true;
    bool es_alfanumerico = true;
    bool es_alfabetico = true;

    while (cadena[i] != '\0') {
       
        if (!(cadena[i] >= '0' && cadena[i] <= '9')) {
            es_numero = false;
        }
        
        if (!((cadena[i] >= '0' && cadena[i] <= '9') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= 'a' && cadena[i] <= 'z'))) {
            es_alfanumerico = false;
        }

        if (!((cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= 'a' && cadena[i] <= 'z'))) {
            es_alfabetico = false;
        }
        i++;
    }

    if (es_numero) {
        return "Numerica";
    } else if (es_alfabetico) {
        return "Alfabetica";
    } else if (es_alfanumerico) {
        return "Alfanumerica";
    } else {
        return "Otro tipo";
    }
}

int main() {

    char cadena[100];
    cout << "Introduce una cadena de caracteres: ";
    cin.getline(cadena, 100);
    cout << "La cadena '" << cadena << "' es: " << tipo_cadena(cadena) << endl;

}
