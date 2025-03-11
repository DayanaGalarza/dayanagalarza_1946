#include <iostream>
#include <iomanip> // Para setw()
using namespace std;

struct persona {
    int id;
    string nombre;
    int edad;
    bool casado = false;
};

void ingresarDatosRegristro(persona per[], int n) {
    char resp;
    cin.ignore(); // Evitar problemas con buffer
    for (int i = 0; i < n; i++) {
        per[i].id = i + 1;
        cout << "Ingrese nombre y apellido: ";
        getline(cin, per[i].nombre); // Captura nombre completo
        cout << "Ingrese edad: ";
        cin >> per[i].edad;
        cout << "Es casado? (S/N): ";
        cin >> resp;
        cin.ignore(); // Evita problemas con el buffer.
        if (resp == 's' || resp == 'S') {
            per[i].casado = true;
        }
    }
}

void mostrarRegistro(persona per[], int n) {
    cout << left << setw(5) << "ID" 
         << setw(20) << "NOMBRE" 
         << setw(5) << "EDAD" 
         << setw(10) << "CASADO" << endl;
    cout << string(40, '-') << endl; // Línea separadora

    for (int i = 0; i < n; i++) {
        cout << left << setw(5) << per[i].id
             << setw(20) << per[i].nombre
             << setw(5) << per[i].edad
             << setw(10) << (per[i].casado ? "Si" : "No") << endl;
    }
}

persona buscarPersonaId(persona per[], int n, int d) {
    for (int i = 0; i < n; i++) {
        if (per[i].id == d) {
            return per[i];
        }
    }
    return {}; // Retorna una estructura vacía si no se encuentra.
}

void buscarPersonaNombres(persona per[], int n, string nombreBuscado) {
    int contador = 0;
    cout << "\nResultados de busqueda por nombre:\n";
    cout << left << setw(5) << "ID" 
         << setw(20) << "NOMBRE" 
         << setw(5) << "EDAD" 
         << setw(10) << "CASADO" << endl;
    cout << string(40, '-') << endl;

    for (int i = 0; i < n; i++) {
        // Extraer solo el primer nombre de la persona
        string primerNombre = per[i].nombre.substr(0, per[i].nombre.find(" "));

        if (primerNombre == nombreBuscado) {
            contador++;
            cout << left << setw(5) << per[i].id
                 << setw(20) << per[i].nombre
                 << setw(5) << per[i].edad
                 << setw(10) << (per[i].casado ? "Si" : "No") << endl;
        }
    }

    if (contador == 0) {
        cout << "No se encontro ninguna persona con ese nombre.\n";
    } else {
        cout << "Total de personas encontradas con el nombre '" << nombreBuscado << "': " << contador << endl;
    }
}

int main() {
    int np, id;
    string nombre;
    
    cout << "Ingrese la cantidad de personas: ";
    cin >> np;
    
    persona personas[np], encontrada;

    ingresarDatosRegristro(personas, np);
    mostrarRegistro(personas, np);

    // Buscar por ID
    cout << "\nIngrese el ID de la persona a buscar: ";
    cin >> id;
    encontrada = buscarPersonaId(personas, np, id);
    
    if (encontrada.id != 0) {
        cout << "Persona encontrada por ID:\n";
        cout << left << setw(5) << "ID" 
             << setw(20) << "NOMBRE" 
             << setw(5) << "EDAD" 
             << setw(10) << "CASADO" << endl;
        cout << string(40, '-') << endl;
        cout << left << setw(5) << encontrada.id
             << setw(20) << encontrada.nombre
             << setw(5) << encontrada.edad
             << setw(10) << (encontrada.casado ? "Si" : "No") << endl;
    } else {
        cout << "No se encontro ninguna persona con ese ID.\n";
    }

    cin.ignore(); // Evitar problemas con getline

    // Buscar por nombre
    cout << "\nIngrese el nombre de la persona a buscar: ";
    getline(cin, nombre);
    buscarPersonaNombres(personas, np, nombre);

    return 0;
}