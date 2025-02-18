#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../LIBRERIAS/Ahorcado.h"
using namespace std;

string palabraAleatoria(string palabras[]){
    srand(time(NULL));
    int numero = rand() % 5;
    return palabras[numero];
}

int opciones(){
    int op;
    cout<< "1. Deportes"<< endl;
    cout<< "2. Animales"<<endl;
    cout<< "3. Frutas"<<endl;
    cin>> op;
    return op;
}
main ()
{
    string palabras[5], palabraSelecionada;
    int op;
    cout << "Juego del Ahorcado" << endl;
    cout<< "-----------------"<< endl;
    cout<< "Elige una categoria"<< endl;
    (op ==1) ? deportes(palabras): (op==2)? animales(palabras): frutas(palabras);
    palabraSelecionada = palabraAleatoria(palabras);
    cout<< palabraSelecionada<< palabraSelecionada;
}
