# include <iostream>
#define MAX 50
using namespace std;

void llenarTabla (int tabla [][MAX], int f, int c){
    for (int i = 0; i < f ; i++){
        for (int j = 0; j < c; j++){
            cout << "Ingrese el valor de la posicion [ " << i << "][ " << j << "]: ";
            cin >> tabla[i][j];
        }
    }
}

void imprimeTabla (int tabla [][MAX], int f, int c){
    for (int i = 0; i < f ; i++){
        for (int j = 0; j < c; j++){
            cout << tabla[i][j] << " \t";
        }
        cout << endl;
    }
}

main (){
    int tabla [MAX][MAX], filas, columnas;
    cout << "Ingrese numero de filas: ";
    cin >> filas;
    cout << "Ingrese numero de columnas: ";
    cin >> columnas;
    llenarTabla (tabla, filas, columnas);
    imprimeTabla (tabla, filas, columnas);
}