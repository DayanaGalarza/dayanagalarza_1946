#include <iostream>
using namespace std;

void cambiarSting(string & nombres){
    nombres = "Sin nombre";
}

void cambiarArray (char apellido[]){

   /* apellido[0] = 'S';
    apellido[1] = 'i';
    apellido[2] = 'n';
    apellido[3] = ' ';
    apellido[4] = 'a';
    apellido[5] = 'p';
    apellido[6] = 'e';
    apellido[7] = 'l';
    apellido[8] = 'l';
    apellido[9] = 'o';
    apellido[10] = '\0'; */ //caracter nulo , para indicar el fin de una cadena 
    cout << "Ingresa el nuevo apellido: ";
    cin.getline (apellido, 20);
}

main (){
    string nombres, apodo;
    char apellido[20], apodo1 [20];
    cout << "Ingrese sus nombres: ";
    getline(cin, nombres); 
    cambiarSting (nombres);
    cout << "Su nombre es luego de llamar a la funcion: " << nombres << endl;
    cout << "Ingrese sus apellidos: ";
    cin.getline (apellido, 20);
    cout << "Su apellido inicial es: " << apellido << endl; 
    cambiarArray (apellido);
    cout << "Su apellido luego de llamar a la funcion es: " << apellido << endl;
   
    
}