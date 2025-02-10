#include <iostream>
#include <string.h>
using namespace std;
int comparaCadenas (char cad1[], char cad2[])
{
    return strcmp(cad1, cad2);
}
void copiaCadena (char cad1[], char cad2[]){
    strcpy(cad1, cad2);
}

void anadeCadena (char cad1[], char cad2[]){
    strcat(cad1, cad2);
}
    

main() {
    char cad1[50], cad2[50], cad3[50];
    int comparacion;
    cout << "Ingrese una cadena: ";
    cin.getline(cad1, 50);
    cout << "Ingrese otra cadena: ";
    cin.getline(cad2, 50);
    comparacion=comparaCadenas(cad1, cad2);
    cout<<"Comparacion: " <<comparacion<<endl;
    (comparacion==0) ? cout << "Las cadenas son iguales" : cout << "Las cadenas son diferentes";
    copiaCadena(cad1, cad2);
    cout << "\nLa cadena copiada es: c1 = " << cad1;
    anadeCadena(cad1, cad2);
    cout << "\nLa cadena anadida es: c1 = " << cad1;
    
}