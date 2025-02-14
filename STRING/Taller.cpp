#include <iostream>
using namespace std;

int main()
{
    string cadena ="informatica ";
    //Borramos los carateres de la cadena
    cadena.clear();
    cout << cadena; //no muestra nada
    //Volvemos a inicializar con un valor
    cadena = "informatica ";

    //Longitud de la cadena 
    cout << "La cadena " << cadena << " tiene " << cadena.length() << " caracteres. " << endl;

    //Primer y ultmo caracter
    cout << "Primer caracte: " << cadena.front () << endl; //Igual que cadena[0]
    cout << "Ultimo caracte: " << cadena.back () << endl; //Igual que cadena[cadena.length()-1]

    //añadir cadenas 
    cadena.append("moderna"); //Es lo mismo que cadena += "moderna"
    cout << cadena << endl;

    //Añadimos un caracter
    char car='0';
    cadena.append(1,car);
    cout << cadena << endl;

    //Volvemos a inicializar con un valor
    cadena= "informatica";

    //buscar carateres
    if(cadena.find("i")!=-1)
    cout << "Posicion del primer caracte i: "<< cadena.find("i") << endl;
    cout <<"Posicion del segundo caracter i: " << cadena.find("i",1) << endl;

    //Extrer subcadenas 
    string subcad;
    subcad=cadena.substr(2,3);
    cout <<subcad << endl;
    subcad=cadena.substr(5);
    cout << subcad << endl;

    //Reemplazar parte de la cadena 
    cadena.replace(6,2,"accion");
    cout << cadena << endl;

    return 0;
}