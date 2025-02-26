#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

struct Estudiante {
    int id;
    string nombre;
    float nota1;
    float nota2;
    float promedio;
    float z_Estandarizada;
    string categoria;
};

float calcularPromedio(float nota1, float nota2) {
    return (nota1 + nota2) / 2.0;
}

float calcularMediaTotal(const vector<Estudiante>& estudiantes) {
    if (estudiantes.empty()) return 0.0;
    float suma = 0.0;
    for (const auto& est : estudiantes) {
        suma += est.promedio;
    }
    return suma / estudiantes.size();
}

float calcularDesviacionEstandar(const vector<Estudiante>& estudiantes, float media) {
    if (estudiantes.empty()) return 0.0;
    float suma_cuadrados = 0.0;
    for (const auto& est : estudiantes) {
        suma_cuadrados += pow(est.promedio - media, 2);
    }
    // Usar N en lugar de N-1 como solicitado
    return sqrt(suma_cuadrados / estudiantes.size());
}

void actualizarEstadisticas(vector<Estudiante>& estudiantes) {
    if (estudiantes.empty()) return;
    
    // Calcular media y desviacion
    float media = calcularMediaTotal(estudiantes);
    float desviacion = calcularDesviacionEstandar(estudiantes, media);
    
    // Asignar Z-estandarizada y categorias
    for (auto& est : estudiantes) {
        // Calcular el valor Z usando la fórmula Z = (X - x̄) / S
        est.z_Estandarizada = (desviacion == 0.0) ? 0.0 : (est.promedio - media) / desviacion;
        
        // Asignar categoria según el Z-estandarizada
        if (est.z_Estandarizada >= 1.0) {
            est.categoria = "A";
        } else if (est.z_Estandarizada >= 0.0) {
            est.categoria = "B";
        } else if (est.z_Estandarizada >= -1.0) {
            est.categoria = "C";
        } else {
            est.categoria = "D";
        }
    }
}

void limpiarBuffer() {
    cin.clear();
    while (cin.get() != '\n');
}

float leerNota(const string& mensaje) {
    float nota;
    cout << mensaje;
    cin >> nota;
    while (cin.fail() || nota < 0 || nota > 20) {
        cin.clear();
        limpiarBuffer();
        cout << "La nota debe ser un valor entre 0 y 20. Intente nuevamente: ";
        cin >> nota;
    }
    return nota;
}

void mostrarListado(const vector<Estudiante>& estudiantes) {
    if (estudiantes.empty()) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }
    
    cout << "\n==================================================================================" << endl;
    cout << setw(5) << "ID" << setw(20) << "Nombre" << setw(10) << "Nota 1" << setw(10) << "Nota 2";
    cout << setw(12) << "Promedio" << setw(10) << "Z-Estandarizada" << setw(10) << "Categoria" << endl;
    cout << "==================================================================================" << endl;
    
    for (const auto& est : estudiantes) {
        cout << setw(5) << est.id 
             << setw(20) << est.nombre 
             << setw(10) << fixed << setprecision(2) << est.nota1
             << setw(10) << est.nota2 
             << setw(12) << est.promedio 
             << setw(10) << est.z_Estandarizada
             << setw(10) << est.categoria << endl;
    }
    
    cout << "==================================================================================" << endl;

    float media = calcularMediaTotal(estudiantes);
    float desviacion = calcularDesviacionEstandar(estudiantes, media); 
    cout << "Media aritmetica: " << fixed << setprecision(2) << media << endl;
    cout << "Desviacion estandar: " << fixed << setprecision(2) << desviacion << endl;
    cout << "==================================================================================" << endl;
}

void agregarEstudiante(vector<Estudiante>& estudiantes, bool mostrarActualizacion = true) {
    Estudiante nuevo;

    nuevo.id = estudiantes.empty() ? 1 : estudiantes.back().id + 1;
    cout << "ID asignado: " << nuevo.id << endl;
    cout << "Ingrese el nombre del estudiante: ";
    limpiarBuffer();
    getline(cin, nuevo.nombre);
    nuevo.nota1 = leerNota("Ingrese la nota 1 (0-20): ");
    nuevo.nota2 = leerNota("Ingrese la nota 2 (0-20): ");
    nuevo.promedio = calcularPromedio(nuevo.nota1, nuevo.nota2);
    estudiantes.push_back(nuevo);
    actualizarEstadisticas(estudiantes);
    
    if (mostrarActualizacion) {
        cout << "Estudiante agregado con exito." << endl;
        cout << "\nListado actualizado de estudiantes:" << endl;
        mostrarListado(estudiantes);
    }
}

void registrarEstudiantes(vector<Estudiante>& estudiantes) {
    int cantidad;
    cout << "Ingrese la cantidad de estudiantes a registrar: ";
    cin >> cantidad;
    while (cin.fail() || cantidad < 0) {
        cin.clear();
        limpiarBuffer();
        cout << "Por favor, ingrese un numero valido de estudiantes: ";
        cin >> cantidad;
    }
    
    for (int i = 0; i < cantidad; i++) {
        cout << "\nRegistrando estudiante " << i+1 << " de " << cantidad << ":" << endl;
        agregarEstudiante(estudiantes, false);
    }
    
    cout << "\nRegistro de estudiantes completado." << endl;
}

void eliminarEstudiante(vector<Estudiante>& estudiantes) {
    if (estudiantes.empty()) {
        cout << "No hay estudiantes para eliminar." << endl;
        return;
    }
    
    int id;
    cout << "Ingrese el ID del estudiante a eliminar: ";
    cin >> id;
    
    if (cin.fail()) {
        cin.clear();
        limpiarBuffer();
        cout << "ID invalido." << endl;
        return;
    }

    bool encontrado = false;
    int indice = -1;
    for (size_t i = 0; i < estudiantes.size(); i++) {
        if (estudiantes[i].id == id) {
            encontrado = true;
            indice = i;
            break;
        }
    }
    
    if (!encontrado) {
        cout << "No se encontro ningun estudiante con el ID " << id << "." << endl;
        return;
    }

    for (size_t i = indice; i < estudiantes.size() - 1; i++) {
        estudiantes[i] = estudiantes[i + 1];
    }
    estudiantes.pop_back(); 
    actualizarEstadisticas(estudiantes);
    cout << "Estudiante eliminado con exito." << endl;
    
    if (!estudiantes.empty()) {
        cout << "\nListado actualizado de estudiantes:" << endl;
        mostrarListado(estudiantes);
    } else {
        cout << "No quedan estudiantes en el sistema." << endl;
    }
}

int main() {
    vector<Estudiante> estudiantes;
    registrarEstudiantes(estudiantes);
    
    if (!estudiantes.empty()) {
        cout << "\nListado de estudiantes registrados:" << endl;
        mostrarListado(estudiantes);
    }
    
    int opcion;
    do {
        cout << "\n=== SISTEMA DE GESTION DE ESTUDIANTES ===" << endl;
        cout << "1. Mostrar listado de estudiantes" << endl;
        cout << "2. Agregar estudiante" << endl;
        cout << "3. Eliminar estudiante" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        if (cin.fail()) {
            cin.clear();
            limpiarBuffer();
            cout << "Opcion invalida. Intente nuevamente." << endl;
            continue;
        }
        
        switch (opcion) {
            case 1: mostrarListado(estudiantes); break;
            case 2: agregarEstudiante(estudiantes); break;
            case 3: eliminarEstudiante(estudiantes); break;
            case 4: cout << "Saliendo del programa. Hasta luego" << endl; break;
            default: cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (opcion != 4);
    
    return 0;
}