#include <iostream>
    using namespace std;

void deportes(string deportes){
    string deportesx[5]={"Futbol", "Tenis", "Baloncesto","Voley","Natacion"};
    for (int i=0; i<5; i++){
        deportes[i]= deportesx[i];
    }
}

void animales(string animales){
    string animalesx[5]={"Perro", "Gato", "Tigre","Leon","Conejo"};
    for (int i=0; i<5; i++){
        animales[i]=animalesx[i];
    }
}

void frutas(string frutas){
    string frutasx[5]={"Manzana", "Pera", "Uva","Cereza","Fresa"};
    for (int i=0; i<5; i++){
        frutas[i]=frutasx[i];
    }
}