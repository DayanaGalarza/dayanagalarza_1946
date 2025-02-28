#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

// Estructura para almacenar los datos de cada estudiante
struct Estudiante {
    int id;
    string nombre;
    float nota1;
    float nota2;
    float promedio;
    float z_Estandarizada;
    string categoria;
};

// Función para calcular el promedio de un estudiante
float calcularPromedio(float nota1, float nota2) {
    return (nota1 + nota2) / 2.0;
}

// Función para calcular la media aritmética de todos los promedios
float calcularMediaTotal(const vector<Estudiante>& estudiantes) {
    float suma = 0.0;
    for (const auto& est : estudiantes) {
        suma += est.promedio;
    }
    return estudiantes.empty() ? 0.0 : suma / estudiantes.size();
}

// Función para calcular la desviación estándar
float calcularDesviacionEstandar(const vector<Estudiante>& estudiantes, float media) {
    float suma_cuadrados = 0.0;
    for (const auto& est : estudiantes) {
        suma_cuadrados += pow(est.promedio - media, 2);
    }
    return estudiantes.size() <= 1 ? 0.0 : sqrt(suma_cuadrados / (estudiantes.size() - 1));
}

// Función para calcular el Z-score de cada estudiante y asignar categorías
void calcularZEstandarizadas(vector<Estudiante>& estudiantes, float media, float desviacion) {
    for (auto& est : estudiantes) {
        est.z_Estandarizada = (desviacion == 0.0) ? 0.0 : (est.promedio - media) / desviacion;

        // Asignar categoría según el z_Estandarizada
        if (est.z_Estandarizada > 1.0) {
            est.categoria = "A";
        } else if (est.z_Estandarizada >= 0.0 && est.z_Estandarizada <= 1.0) {
            est.categoria = "B";
        } else if (est.z_Estandarizada >= -1.0 && est.z_Estandarizada < 0.0) {
            est.categoria = "C";
        } else {
            est.categoria = "D";
        }
    }
}

// Función para limpiar el buffer de entrada
void limpiarBuffer() {
    cin.clear();
    while (cin.get() != '\n');
}

// Función para mostrar los estudiantes en forma de tabla
void mostrarListado(const vector<Estudiante>& estudiantes) {
    if (estudiantes.empty()) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }

    cout << "\n==================================================================================" << endl;
    cout << setw(5) << "ID" << setw(20) << "Nombre" << setw(10) << "Nota 1" << setw(10) << "Nota 2";
    cout << setw(12) << "Promedio" << setw(10) << "Z-Estamdarizada" << setw(10) << "Categoria" << endl;
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

    // Calcular y mostrar estadísticas
    float media = calcularMediaTotal(estudiantes);
    float desviacion = calcularDesviacionEstandar(estudiantes, media);

    cout << "Media aritmetica: " << fixed << setprecision(2) << media << endl;
    cout << "Desviacion estandar: " << fixed << setprecision(2) << desviacion << endl;
    cout << "==================================================================================" << endl;
}

// Función para registrar estudiantes al inicio
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
        Estudiante nuevo;

        // Generar ID automáticamente
        nuevo.id = estudiantes.empty() ? 1 : estudiantes.back().id + 1;

        cout << "\nRegistrando estudiante " << i + 1 << " de " << cantidad << ":" << endl;
        cout << "ID asignado: " << nuevo.id << endl;

        cout << "Ingrese el nombre del estudiante: ";
        limpiarBuffer();
        getline(cin, nuevo.nombre);

        cout << "Ingrese la nota 1: ";
        cin >> nuevo.nota1;
        while (cin.fail() || nuevo.nota1 < 0) {
            cin.clear();
            limpiarBuffer();
            cout << "La nota debe ser un valor numerico positivo. Intente nuevamente: ";
            cin >> nuevo.nota1;
        }

        cout << "Ingrese la nota 2: ";
        cin >> nuevo.nota2;
        while (cin.fail() || nuevo.nota2 < 0) {
            cin.clear();
            limpiarBuffer();
            cout << "La nota debe ser un valor numerico positivo. Intente nuevamente: ";
            cin >> nuevo.nota2;
        }

        nuevo.promedio = calcularPromedio(nuevo.nota1, nuevo.nota2);
        estudiantes.push_back(nuevo);
    }

    // Recalcular Z-scores y categorías para todos los estudiantes
    if (!estudiantes.empty()) {
        float media = calcularMediaTotal(estudiantes);
        float desviacion = calcularDesviacionEstandar(estudiantes, media);
        calcularZEstandarizadas(estudiantes, media, desviacion);
    }

    cout << "\nRegistro de estudiantes completado." << endl;
}

// Función para modificar la información de un estudiante
void modificarEstudiante(vector<Estudiante>& estudiantes) {
    int id;
    cout << "Ingrese el ID del estudiante a modificar: ";
    cin >> id;

    bool encontrado = false;
    for (auto& est : estudiantes) {
        if (est.id == id) {
            encontrado = true;
            cout << "Estudiante encontrado: " << est.nombre << endl;
            int opcion;
            do {
                cout << "\nSeleccione qué desea modificar:" << endl;
                cout << "1. Nombre" << endl;
                cout << "2. Nota 1" << endl;
                cout << "3. Nota 2" << endl;
                cout << "4. Salir" << endl;
                cout << "Seleccione una opcion: ";
                cin >> opcion;

                switch (opcion) {
                    case 1:
                        cout << "Ingrese el nuevo nombre: ";
                        limpiarBuffer();
                        getline(cin, est.nombre);
                        break;
                    case 2:
                        cout << "Ingrese la nueva nota 1: ";
                        cin >> est.nota1;
                        while (cin.fail() || est.nota1 < 0) {
                            cin.clear();
                            limpiarBuffer();
                            cout << "La nota debe ser un valor numerico positivo. Intente nuevamente: ";
                            cin >> est.nota1;
                        }
                        break;
                    case 3:
                        cout << "Ingrese la nueva nota 2: ";
                        cin >> est.nota2;
                        while (cin.fail() || est.nota2 < 0) {
                            cin.clear();
                            limpiarBuffer();
                            cout << "La nota debe ser un valor numerico positivo. Intente nuevamente: ";
                            cin >> est.nota2;
                        }
                        break;
                    case 4:
                        cout << "Saliendo..." << endl;
                        break;
                    default:
                        cout << "Opción inválida. Intente nuevamente." << endl;
                }

                // Recalcular el promedio y las estadísticas
                est.promedio = calcularPromedio(est.nota1, est.nota2);
                float media = calcularMediaTotal(estudiantes);
                float desviacion = calcularDesviacionEstandar(estudiantes, media);
                calcularZEstandarizadas(estudiantes, media, desviacion);

            } while (opcion != 4);

            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontró un estudiante con el ID " << id << endl;
    }
}

// Función principal que contiene el menú de opciones
int main() {
    vector<Estudiante> estudiantes;

    // Registro inicial de estudiantes
    registrarEstudiantes(estudiantes);

    int opcion;
    do {
        cout << "\n=== SISTEMA DE GESTION DE ESTUDIANTES ===" << endl;
        cout << "1. Mostrar listado de estudiantes" << endl;
        cout << "2. Agregar estudiante" << endl;
        cout << "3. Eliminar estudiante" << endl;
        cout << "4. Modificar estudiante" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            limpiarBuffer();
            cout << "Opción invalida. Intente nuevamente." << endl;
            continue;
        }

        switch (opcion) {
            case 1:
                mostrarListado(estudiantes);
                break;
            case 2:
                agregarEstudiante(estudiantes);
                break;
            case 3:
                eliminarEstudiante(estudiantes);
                break;
            case 4:
                modificarEstudiante(estudiantes);
                break;
            case 5:
                cout << "Saliendo del programa. Hasta luego." << endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
        }
    } while (opcion != 5);

    return 0;
}
