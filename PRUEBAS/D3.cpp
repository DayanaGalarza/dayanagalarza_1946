#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int obtenerEleccionUsuario() {
    int eleccion;
    cout << "\nElija su jugada:" << endl;
    cout << "1. Piedra" << endl;
    cout << "2. Papel" << endl;
    cout << "3. Tijera" << endl;
    cout << "Su eleccion: ";
    
    do {
        cin >> eleccion;
        if (eleccion < 1 || eleccion > 3) {
            cout << "Opción inválida. Intente nuevamente (1-3): ";
        }
    } while (eleccion < 1 || eleccion > 3);
    
    return eleccion;
}

int obtenerEleccionMaquina() {
    return (rand() % 3) + 1;
}

void mostrarEleccion(int eleccion) {
    switch(eleccion) {
        case 1: cout << "Piedra"; break;
        case 2: cout << "Papel"; break;
        case 3: cout << "Tijera"; break;
    }
}

int determinarGanadorRonda(int jugador, int maquina) {
    if (jugador == maquina) return 0;
    
    if ((jugador == 1 && maquina == 3) || 
        (jugador == 2 && maquina == 1) || 
        (jugador == 3 && maquina == 2))   
        return 1; 
    
    return -1;
}

void determinarGanadorJuego(int puntosJugador, int puntosMaquina) {
    cout << "\n=== Resultado Final ===" << endl;
    cout << "Jugador: " << puntosJugador << " puntos" << endl;
    cout << "Maquina: " << puntosMaquina << " puntos" << endl;
    
    if (puntosJugador > puntosMaquina)
        cout << "¡Felicidades! ¡Has ganado el juego!" << endl;
    else if (puntosMaquina > puntosJugador)
        cout << "La maquina ha ganado el juego." << endl;
    else
        cout << "¡El juego ha terminado en empate!" << endl;
}

int main() {
    srand(time(0)); 
    int dificultad, puntosJugador = 0, puntosMaquina = 0;
    
    cout << "=== Piedra, Papel o Tijera ===" << endl;
    cout << "Seleccione nivel de dificultad:" << endl;
    cout << "1. Principiante" << endl;
    cout << "2. Intermedio" << endl;
    cout << "3. Avanzado" << endl;
    cout << "Su eleccion: ";
    
    do {
        cin >> dificultad;
        if (dificultad < 1 || dificultad > 3)
            cout << "Opcian invalida. Intente nuevamente (1-3): ";
    } while (dificultad < 1 || dificultad > 3);
    
    switch(dificultad) {
        case 2: puntosMaquina = 1; break;  
        case 3: puntosMaquina = 2; break; 
    }
    
    cout << "\nPuntos iniciales:" << endl;
    cout << "Jugador: " << puntosJugador << endl;
    cout << "Maquina: " << puntosMaquina << endl;
    
\
    for (int ronda = 1; ronda <= 5; ronda++) {
        cout << "\n=== Ronda " << ronda << " ===" << endl;
        
        int eleccionJugador = obtenerEleccionUsuario();
        int eleccionMaquina = obtenerEleccionMaquina();
        
        cout << "Tu elección: ";
        mostrarEleccion(eleccionJugador);
        cout << "\nMaquina elige: ";
        mostrarEleccion(eleccionMaquina);
        cout << endl;
        
        int resultado = determinarGanadorRonda(eleccionJugador, eleccionMaquina);
        
        if (resultado == 1) {
            cout << "¡Ganaste la ronda!" << endl;
            puntosJugador++;
        } else if (resultado == -1) {
            cout << "La maquina gana la ronda." << endl;
            puntosMaquina++;
        } else {
            cout << "¡Empate!" << endl;
        }
        
        cout << "Puntuación actual - Jugador: " << puntosJugador << " Maquina: " << puntosMaquina << endl;
    }
    
    determinarGanadorJuego(puntosJugador, puntosMaquina);
    
    return 0;
}