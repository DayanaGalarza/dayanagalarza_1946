#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char obtenerEleccionUsuario() {
    char eleccion;
    cout << "Elige (Piedra - P, Papel - A, Tijera - T): ";
    cin >> eleccion;
    while (eleccion != 'P' && eleccion != 'A' && eleccion != 'T') {
        cout << "Entrada no válida. Elige (Piedra - P, Papel - A, Tijera - T): ";
        cin >> eleccion;
    }
    return eleccion;
}

char obtenerEleccionMaquina(int nivel) {
    srand(time(0)); 
    int eleccion = rand() % 3;  

   
    if (nivel == 1) {

        return eleccion == 0 ? 'P' : (eleccion == 1 ? 'A' : 'T');
    } else if (nivel == 2) {

        if (rand() % 2 == 0) {
           
            return eleccion == 0 ? 'A' : (eleccion == 1 ? 'T' : 'P');
        } else {
            return eleccion == 0 ? 'P' : (eleccion == 1 ? 'A' : 'T');
        }
    } else {
        
        return eleccion == 0 ? 'A' : (eleccion == 1 ? 'T' : 'P');
    }
}


int determinarGanador(char usuario, char maquina) {
    if (usuario == maquina) {
        return 0;  
    }
    if ((usuario == 'P' && maquina == 'T') || 
        (usuario == 'A' && maquina == 'P') || 
        (usuario == 'T' && maquina == 'A')) {
        return 1;  
    }
    return -1;  
}


void determinarGanadorDelJuego(int puntosUsuario, int puntosMaquina) {
    if (puntosUsuario > puntosMaquina) {
        cout << "¡Felicidades! Has ganado el juego." << endl;
    } else if (puntosUsuario < puntosMaquina) {
        cout << "La máaquina ha ganado el juego. Mejor suerte la proxima vez." << endl;
    } else {
        cout << "El juego ha terminado en empate." << endl;
    }
}

int main() {
    int nivel;
    int puntosUsuario = 0, puntosMaquina = 0;

    cout << "Selecciona el nivel de dificultad:\n";
    cout << "1. Principiante\n";
    cout << "2. Intermedio\n";
    cout << "3. Avanzado\n";
    cout << "Elige tu nivel (1, 2 o 3): ";
    cin >> nivel;

    
    if (nivel == 2) {
        puntosMaquina = 1;  
    } else if (nivel == 3) {
        puntosMaquina = 2;  
    }

    for (int i = 1; i <= 5; i++) {
        cout << "\nRonda " << i << ":\n";
        
        char eleccionUsuario = obtenerEleccionUsuario();
        char eleccionMaquina = obtenerEleccionMaquina(nivel);
        
        cout << "La maquina elige: " << (eleccionMaquina == 'P' ? "Piedra" : (eleccionMaquina == 'A' ? "Papel" : "Tijera")) << endl;
        
        int resultado = determinarGanador(eleccionUsuario, eleccionMaquina);
        
        if (resultado == 1) {
            cout << "¡Has ganado esta ronda!" << endl;
            puntosUsuario++;
        } else if (resultado == -1) {
            cout << "La maquina gana esta ronda." << endl;
            puntosMaquina++;
        } else {
            cout << "Esta ronda es un empate." << endl;
        }
        
        cout << "Puntajes - Usuario: " << puntosUsuario << " | Maquina: " << puntosMaquina << endl;
    }

    determinarGanadorDelJuego(puntosUsuario, puntosMaquina);

    return 0;
}
