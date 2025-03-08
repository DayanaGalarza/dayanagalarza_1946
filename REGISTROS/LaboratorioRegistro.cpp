#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

struct Estudiante
{
    int id;
    string nombre;
    float nota1;
    float nota2;
    float promedio;
    float z_Estandarizada;
    string categoria;
};

float calcularPromedio(float nota1, float nota2)
{
    return (nota1 + nota2) / 2.0;
}

float calcularMediaTotal(const vector<Estudiante> &estudiantes)
{
    if (estudiantes.empty())
        return 0.0;
    float suma = 0.0;
    for (const auto &est : estudiantes)
    {
        suma += est.promedio;
    }
    return suma / estudiantes.size();
}

float calcularDesviacionEstandar(const vector<Estudiante> &estudiantes, float media)
{
    if (estudiantes.empty())
        return 0.0;
    float suma_cuadrados = 0.0;
    for (const auto &est : estudiantes)
    {
        suma_cuadrados += pow(est.promedio - media, 2);
    }
    // Usar N en lugar de N-1 como solicitado
    return sqrt(suma_cuadrados / estudiantes.size());
}

<<<<<<< HEAD
// Función para calcular el Z-score de cada estudiante y asignar categorías
void calcularZEstandarizadas(vector<Estudiante>& estudiantes, float media, float desviacion) {
    for (auto& est : estudiantes) {
        est.z_Estandarizada = (desviacion == 0.0) ? 0.0 : (est.promedio - media) / desviacion;

        // Asignar categoría según el z_Estandarizada
        if (est.z_Estandarizada > 1.0) {
=======
void actualizarEstadisticas(vector<Estudiante> &estudiantes)
{
    if (estudiantes.empty())
        return;

    // Calcular media y desviacion
    float media = calcularMediaTotal(estudiantes);
    float desviacion = calcularDesviacionEstandar(estudiantes, media);

    // Asignar Z-estandarizada y categorias
    for (auto &est : estudiantes)
    {
        // Calcular el valor Z usando la fórmula Z = (X - x̄) / S
        est.z_Estandarizada = (desviacion == 0.0) ? 0.0 : (est.promedio - media) / desviacion;

        // Asignar categoria según el Z-estandarizada
        if (est.z_Estandarizada >= 1.0)
        {
>>>>>>> b6e7bf65f6db7fd29c92c3709e1483bc2549db97
            est.categoria = "A";
        }
        else if (est.z_Estandarizada >= 0.0)
        {
            est.categoria = "B";
        }
        else if (est.z_Estandarizada >= -1.0)
        {
            est.categoria = "C";
<<<<<<< HEAD
        } else {
=======
        }
        else
        {
>>>>>>> b6e7bf65f6db7fd29c92c3709e1483bc2549db97
            est.categoria = "D";
        }
    }
}

void limpiarBuffer()
{
    cin.clear();
    while (cin.get() != '\n')
        ;
}

float leerNota(const string &mensaje)
{
    float nota;
    cout << mensaje;
    cin >> nota;
    while (cin.fail() || nota < 0 || nota > 20)
    {
        cin.clear();
        limpiarBuffer();
        cout << "La nota debe ser un valor entre 0 y 20. Intente nuevamente: ";
        cin >> nota;
    }
    return nota;
}

void mostrarListado(const vector<Estudiante> &estudiantes)
{
    if (estudiantes.empty())
    {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }

    cout << "\n==================================================================================" << endl;
    cout << setw(5) << "ID" << setw(20) << "Nombre" << setw(10) << "Nota 1" << setw(10) << "Nota 2";
    cout << setw(12) << "Promedio" << setw(10) << "Z-Estandarizada" << setw(10) << "Categoria" << endl;
    cout << "==================================================================================" << endl;

<<<<<<< HEAD
    for (const auto& est : estudiantes) {
=======
    for (const auto &est : estudiantes)
    {
>>>>>>> b6e7bf65f6db7fd29c92c3709e1483bc2549db97
        cout << setw(5) << est.id
             << setw(20) << est.nombre
             << setw(10) << fixed << setprecision(2) << est.nota1
             << setw(10) << est.nota2
             << setw(12) << est.promedio
             << setw(10) << est.z_Estandarizada
             << setw(10) << est.categoria << endl;
    }

    cout << "==================================================================================" << endl;

<<<<<<< HEAD
    // Calcular y mostrar estadísticas
    float media = calcularMediaTotal(estudiantes);
    float desviacion = calcularDesviacionEstandar(estudiantes, media);

=======
    float media = calcularMediaTotal(estudiantes);
    float desviacion = calcularDesviacionEstandar(estudiantes, media);
>>>>>>> b6e7bf65f6db7fd29c92c3709e1483bc2549db97
    cout << "Media aritmetica: " << fixed << setprecision(2) << media << endl;
    cout << "Desviacion estandar: " << fixed << setprecision(2) << desviacion << endl;
    cout << "==================================================================================" << endl;
}

void agregarEstudiante(vector<Estudiante> &estudiantes, bool mostrarActualizacion = true)
{
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

    if (mostrarActualizacion)
    {
        cout << "Estudiante agregado con exito." << endl;
        cout << "\nListado actualizado de estudiantes:" << endl;
        mostrarListado(estudiantes);
    }
}

void registrarEstudiantes(vector<Estudiante> &estudiantes)
{
    int cantidad;
    cout << "Ingrese la cantidad de estudiantes a registrar: ";
    cin >> cantidad;
<<<<<<< HEAD

    while (cin.fail() || cantidad < 0) {
=======
    while (cin.fail() || cantidad < 0)
    {
>>>>>>> b6e7bf65f6db7fd29c92c3709e1483bc2549db97
        cin.clear();
        limpiarBuffer();
        cout << "Por favor, ingrese un numero valido de estudiantes: ";
        cin >> cantidad;
    }

<<<<<<< HEAD
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
=======
    for (int i = 0; i < cantidad; i++)
    {
        cout << "\nRegistrando estudiante " << i + 1 << " de " << cantidad << ":" << endl;
        agregarEstudiante(estudiantes, false);
    }

    cout << "\nRegistro de estudiantes completado." << endl;
}

void eliminarEstudiante(vector<Estudiante> &estudiantes)
{
    if (estudiantes.empty())
    {
        cout << "No hay estudiantes para eliminar." << endl;
        return;
    }

>>>>>>> b6e7bf65f6db7fd29c92c3709e1483bc2549db97
    int id;
    cout << "Ingrese el ID del estudiante a modificar: ";
    cin >> id;

<<<<<<< HEAD
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

=======
    if (cin.fail())
    {
        cin.clear();
        limpiarBuffer();
        cout << "ID invalido." << endl;
        return;
    }

    bool encontrado = false;
    int indice = -1;
    for (size_t i = 0; i < estudiantes.size(); i++)
    {
        if (estudiantes[i].id == id)
        {
            encontrado = true;
            indice = i;
>>>>>>> b6e7bf65f6db7fd29c92c3709e1483bc2549db97
            break;
        }
    }

<<<<<<< HEAD
    if (!encontrado) {
        cout << "No se encontró un estudiante con el ID " << id << endl;
=======
    if (!encontrado)
    {
        cout << "No se encontro ningun estudiante con el ID " << id << "." << endl;
        return;
    }

    for (size_t i = indice; i < estudiantes.size() - 1; i++)
    {
        estudiantes[i] = estudiantes[i + 1];
    }
    estudiantes.pop_back();
    actualizarEstadisticas(estudiantes);
    cout << "Estudiante eliminado con exito." << endl;

    if (!estudiantes.empty())
    {
        cout << "\nListado actualizado de estudiantes:" << endl;
        mostrarListado(estudiantes);
    }
    else
    {
        cout << "No quedan estudiantes en el sistema." << endl;
>>>>>>> b6e7bf65f6db7fd29c92c3709e1483bc2549db97
    }
}

void modificarNota(vector<Estudiante> &estudiantes)
{
    float nuevaNota;
    int opcion, id;
    cout << "Ingrese el ID del estudiante a modificar: ";
    cin >> id;
    bool encontrado = false;

    for (auto &est : estudiantes)
    {
        if (est.id == id)
        {
            encontrado = true;
            cout << "Seleccione la nota que desea modificar: " << endl;
            cout << "1. Nota 1" << endl;
            cout << "2. Nota 2" << endl;
            cin >> opcion;

            while (opcion < 1 || opcion > 2)
            {
                cout << "Opcion no valida. Intente nuevamente: " << endl;
                cin >> opcion;
            }
            if (opcion == 1)
            {
                cout << "Ingrese la nueva nota 1: ";
                cin >> nuevaNota;
                while (nuevaNota < 0 || nuevaNota > 20)
                {
                    cout << "La nueva nota debe ser un valor entre 0 y 20. Intente nuevamente: ";
                    cin >> nuevaNota;
                }
                est.nota1 = nuevaNota;
            }
            else if (opcion == 2)
            {
                cout << "Ingrese la nueva nota 2: ";
                cin >> nuevaNota;
                while (nuevaNota < 0 || nuevaNota > 20)
                {
                    cout << "La nueva nota debe ser un valor entre 0 y 20. Intente nuevamente: ";
                    cin >> nuevaNota;
                }
                est.nota2 = nuevaNota;
            }
            est.promedio = calcularPromedio(est.nota1, est.nota2);
            actualizarEstadisticas(estudiantes);

            cout << "Nota modificada con exito. El promedio y la categoria han sido actualizados." << endl;
            mostrarListado(estudiantes);
        }
    }

    if (!encontrado)
    {
        cout << "No se encontro un estudiante con el ID " << id << "." << endl;
    }
}

void modificarNombre(vector<Estudiante> &estudiantes)
{
    int id;
    cout << "Ingrese el ID del estudiante a modificar: ";
    cin >> id;
    bool encontrado = false;

    for (auto &est : estudiantes)
    {
        if (est.id == id)
        {
            encontrado = true;
            cout << "Ingrese el nuevo nombre del estudiante: ";
            cin.ignore();
            getline(cin, est.nombre);
            cout << "Nombre modificado con exito." << endl;
            mostrarListado(estudiantes);
        }
    }
    if (!encontrado)
    {
        cout << "No se encontro un estudiante con el ID " << id << "." << endl;
    }
}

int main()
{
    vector<Estudiante> estudiantes;
<<<<<<< HEAD

    // Registro inicial de estudiantes
    registrarEstudiantes(estudiantes);

=======
    registrarEstudiantes(estudiantes);

    if (!estudiantes.empty())
    {
        cout << "\nListado de estudiantes registrados:" << endl;
        mostrarListado(estudiantes);
    }

>>>>>>> b6e7bf65f6db7fd29c92c3709e1483bc2549db97
    int opcion;
    do
    {
        cout << "\n=== SISTEMA DE GESTION DE ESTUDIANTES ===" << endl;
        cout << "1. Mostrar listado de estudiantes" << endl;
        cout << "2. Agregar estudiante" << endl;
        cout << "3. Eliminar estudiante" << endl;
<<<<<<< HEAD
        cout << "4. Modificar estudiante" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
=======
        cout << "4. Modificar calificacion" << endl;
        cout << "5. Modificar nombre" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (cin.fail())
        {
>>>>>>> b6e7bf65f6db7fd29c92c3709e1483bc2549db97
            cin.clear();
            limpiarBuffer();
            cout << "Opcion invalida. Intente nuevamente." << endl;
            continue;
        }

<<<<<<< HEAD
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
=======
        switch (opcion)
        {
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
            modificarNota(estudiantes);
            break;
        case 5:
            modificarNombre(estudiantes);
            break;
        case 6:
            cout << "Saliendo del programa. Hasta luego" << endl;
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (opcion != 6);
>>>>>>> b6e7bf65f6db7fd29c92c3709e1483bc2549db97

    return 0;
}
