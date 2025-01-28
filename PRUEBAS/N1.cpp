#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <string>

using namespace std;

int EleccionUsuario() {
    int eleccion;
    cout << "Elige una opcion:\n";
    cout << "1. Piedra\n";
    cout << "2. Papel\n";
    cout << "3. Tijera\n";
    cout << " seleccOpcion: ";
    cin >> eleccion;

    while (eleccion < 1 || eleccion > 3) {
        cout << "Intentalo de nuevo: "; 
        cin >> eleccion;
    }

    return eleccion; 
}

int EleccionMaquina() {
	
    return rand() % 3 + 1;
}

string determinarGanadorRonda(int eleccionUsuario, int eleccionMaquina) {
    string opciones[] = {"Piedra", "Papel", "Tijera"};
    cout << "Tu elegiste: " << opciones[eleccionUsuario - 1] << endl;
    cout << "La maquina eligio: " << opciones[eleccionMaquina - 1] << endl;

    if (eleccionUsuario == eleccionMaquina) {
        return "Empate en esta ronda.";
    } else if ((eleccionUsuario == 1 && eleccionMaquina == 3) || 
               (eleccionUsuario == 2 && eleccionMaquina == 1) || 
               (eleccionUsuario == 3 && eleccionMaquina == 2)) { 
        return "Ganaste esta ronda.";
    } else {
        return "Perdiste esta ronda.";
    }
}

void determinarGanadorJuego(int puntosUsuario, int puntosMaquina) {
    cout << "\n--- Resultado Final ---\n";
    cout << "Puntos Usuario: " << puntosUsuario << " | Puntos Maquina: " << puntosMaquina << endl;

    if (puntosUsuario > puntosMaquina) {
        cout << "ERES EL GANADOR :D";
    } else if (puntosUsuario < puntosMaquina) {
        cout << "LA MAQUINA ES LA GANDORA :,,,C";
    } else {
        cout << "EMPATE";
    }
}

int main() {
    
    srand(time(0));

    int puntosUsuario = 0, puntosMaquina = 0;
    
    cout << "Selecciona el nivel de dificultad:\n";
    cout << "1. Principiante (0-0)\n";
    cout << "2. Intermedio (Usuario 0 - Maquina 1)\n";
    cout << "3. Avanzado (Usuario 0 - Maquina 2)\n";
    cout << "Opcion: ";
    int dificultad;
    cin >> dificultad;

    if (dificultad == 2) {
        puntosMaquina = 1;
    } else if (dificultad == 3) {
        puntosMaquina = 2;
    }

    for (int ronda = 1; ronda <= 5; ronda++) {
        cout << "\n--- Ronda " << ronda << " ---\n";

        
        int eleccionUsuario = EleccionUsuario();
        int eleccionMaquina = EleccionMaquina();

        string resultado = determinarGanadorRonda(eleccionUsuario, eleccionMaquina);
        cout << resultado << endl;

        if (resultado.find("Ganaste") != string::npos) {
            puntosUsuario++;
        } else if (resultado.find("Perdiste") != string::npos) {
            puntosMaquina++;
        }

        cout << "Puntos Usuario: " << puntosUsuario << " | Puntos Maquina: " << puntosMaquina << endl;
    }

    determinarGanadorJuego(puntosUsuario, puntosMaquina);

    return 0;
}