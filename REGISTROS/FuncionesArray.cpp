#include <iostream>

using namespace std;

struct persona
{
    int id;
    string nombre;
    int edad;
    bool casado=false;
};
void ingresasDatosRegistro(persona per[], int n){
    int i;
    char resp;
    for(i=0; i<n; i++){
        per[i].id=i+1;
        cout << "Ingrese el Nombre: ";
        cin >> per[i].nombre;
        cout << "Ingrese la Edad: ";
        cin >> per[i].edad;
        cout << "Es Casado? <<S/N>>: ";
        cin.get(resp);
        cin.ignore();
        if(resp=='s' || resp=='S'){
            per[i].casado=true;
        }
    }
}

void mostrerDatosRegistro(persona per[], int n){
    int i;
    cout << "ID\tNombre\tEdad\tCasado" << endl;
    for(i=0; i<n; i++){
        cout << per[i].id << "\t";
        cout << per[i].nombre << "\t";
        cout << per[i].edad << "\t";
        cout << per[i].casado<< endl;
    }
}

main()
{
    int np;
    cout << "Ingrese la cantidad de personas: ";
    cin >> np;
    persona personas[np];
    ingresasDatosRegistro(personas, np);
    mostrerDatosRegistro(personas, np);
}
