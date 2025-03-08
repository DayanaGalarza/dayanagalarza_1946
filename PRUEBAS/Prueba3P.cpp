#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int DIAS_SEMANA = 7;
const int NUM_CONDUCTORES = 5;

int main() {
    srand(time(nullptr));  
    vector<string> nombres = {"Stalin ", "John ", "Jair ", "Maraleth ", "Katherine "};
    vector<vector<float>> kms(NUM_CONDUCTORES, vector<float>(DIAS_SEMANA, 0));
    vector<float> totalKms(NUM_CONDUCTORES, 0);
    
    for (int i = 0; i < NUM_CONDUCTORES; i++) {
        for (int j = 0; j < DIAS_SEMANA; j++) {
            // Genera un número aleatorio entre 50 y 150 km
            kms[i][j] = 50 + (rand() % 101);
            totalKms[i] += kms[i][j];
        }
    }
    
    // Mostrar tabla de conductores con kilometros por dia
    cout << "\n====================================================================" << endl;
    cout << "           TABLA DE KILOMETROS RECORRIDOS POR CONDUCTORES           " << endl;
    cout << "====================================================================" << endl;
    
    cout << left << setw(20) << "Conductor";
    cout << setw(10) << "Lunes";
    cout << setw(10) << "Martes";
    cout << setw(10) << "Miercoles";
    cout << setw(10) << "Jueves";
    cout << setw(10) << "Viernes";
    cout << setw(10) << "Sabado";
    cout << setw(10) << "Domingo";
    cout << setw(10) << "TOTAL" << endl;
    
    cout << "--------------------------------------------------------------------" << endl;
    
    // Datos de la tabla
    for (int i = 0; i < NUM_CONDUCTORES; i++) {
        cout << left << setw(20) << nombres[i];
        for (int j = 0; j < DIAS_SEMANA; j++) {
            cout << setw(10) << fixed << setprecision(1) << kms[i][j];
        }
        cout << setw(10) << fixed << setprecision(1) << totalKms[i] << endl;
    }
    
    cout << "====================================================================" << endl;
    
    //Encontrar conductor con mayor kilometraje
    int conductorMax = 0;
    for (int i = 1; i < NUM_CONDUCTORES; i++) {
        if (totalKms[i] > totalKms[conductorMax]) {
            conductorMax = i;
        }
    }
    
    cout << "\nConductor con mas kilometros recorridos:" << endl;
    cout << nombres[conductorMax] << " con " << fixed << setprecision(1) << totalKms[conductorMax] << " km" << endl;
    
    //Representación gráfica
    cout << "\nRepresentacion grafica de kilometros:" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    
    // Crear un vector de índices para ordenar
    vector<int> indices(NUM_CONDUCTORES);
    for (int i = 0; i < NUM_CONDUCTORES; i++) {
        indices[i] = i;
    }

    // Ordenar los índices según el kilometraje en orden descendente
    for (int i = 0; i < NUM_CONDUCTORES - 1; i++) {
        for (int j = i + 1; j < NUM_CONDUCTORES; j++) {
            if (totalKms[indices[i]] < totalKms[indices[j]]) {
                swap(indices[i], indices[j]);
            }
        }
    }

    // Mostrar la representación gráfica ordenada por kilometraje
    for (int i = 0; i < NUM_CONDUCTORES; i++) {
        int idx = indices[i];
        cout << left << setw(20) << nombres[idx] << ": ";
        int barras = static_cast<int>(totalKms[idx] / 100);
        for (int j = 0; j < barras; j++) {
            cout << "^";
        }
        cout << " (" << fixed << setprecision(1) << totalKms[idx] << " km)" << endl;
    }
    
    return 0;
}