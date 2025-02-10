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

bool alfabeticoNumerico (char cad1[]){
    bool alfabeticoNumerico = true;
    for (int i=0; i<strlen (cad1); i++){
        if (isalnum(cad1[i])==false){
            alfabeticoNumerico = false;
            break;
        }
    }
    return alfabeticoNumerico;
}

bool alfabetico (char cad1[]){
    bool alfabetico = true;
    for (int i=0; i<strlen (cad1); i++){
        if (isalpha(cad1[i])==false){
            alfabetico = false;
            break;
        }
    }
    return alfabetico;
}

bool numerico (char cad1[]){
    bool numerico = true;
    for (int i=0; i<strlen (cad1); i++){
        if (isdigit(cad1[i])==false){
            numerico = false;
            break;
        }
    }
    return numerico;
}

bool esespacio (char cad1[]){
    bool esespacio = true;
    for (int i=0; i<strlen (cad1); i++){
        if (isspace(cad1[i])==false){
            esespacio = false;
            break;
        }
    }
    return esespacio;
}

bool esMayusculas(char cad1[]){
    bool mayuscula = true;
    for (int i=0; i<strlen (cad1); i++){
        if (isupper(cad1[i])==false){
            mayuscula = false;
            break;
        }
    }
    return mayuscula;
}

bool esMinuscula(char cad1[]){
    bool Minuscula = true;
    for (int i=0; i<strlen (cad1); i++){
        if (islower(cad1[i])==false){
            Minuscula = false;
            break;
        }
    }
    return Minuscula;
}

void mayuscula(char cad1[]){
    for (int i=0; i<strlen (cad1); i++){
        cad1[i] = toupper (cad1[i]);
    }
}

void minuscula(char cad1[]){
    for (int i=0; i<strlen (cad1); i++){
        cad1[i] = tolower (cad1[i]);
    }
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
    // copiaCadena(cad1, cad2);
    //cout << "\nLa cadena copiada es: c1 = " << cad1;
    //anadeCadena(cad1, cad2);
    //cout << "\nLa cadena anadida es: c1 = " << cad1;
    (alfabeticoNumerico(cad1))? cout << "\nLa cadena" << cad1 << " es alfanumerica" : cout << "\nLa cadena" <<cad1<< " no es alfanumerica";
    (alfabetico(cad1))? cout << "\nLa cadena" << cad1 << " es alfabetica" : cout << "\nLa cadena" << cad1<< " no es alfabetica";
    (numerico(cad1))? cout << "\nLa cadena" << cad1 << " es numerica" : cout << "\nLa cadena" << cad1<< " no es numerica";
    (esespacio(cad1))? cout << "\nLa cadena" << cad1 << " es un espacio" : cout << "\nLa cadena" << cad1<< " no es un espacio";
    (esMayusculas(cad1))? cout << "\nLa cadena" << cad1 << " es mayuscula" : cout << "\nLa cadena" << cad1<< " no es mayuscula";
    (esMinuscula(cad1))? cout << "\nLa cadena" << cad1 << " es minuscula" : cout << "\nLa cadena" << cad1<< " no es minuscula";
    mayuscula(cad1);
    cout << "\nLa cadena en mayusculas es: " << cad1;
    minuscula(cad1);
    cout << "\nLa cadena en minusculas es: " << cad1;
}