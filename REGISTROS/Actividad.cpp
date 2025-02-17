#include <iostream>
using namespace std;

struct {
    string marca;
    string modelo;
    int anyo;
    char placa;
}a1,e2;


main ()
{
    cout<<"Datos del automovil"<<endl;
    cout<<"Marca: ";
    cin.ignore();
    getline(cin, a1.marca);
    cout<<"Modelo: ";
    cin.ignore();
    getline(cin, a1.modelo);
    cout<<"Anyo: ";
    cin>>a1.anyo;
    cout<<"Placa: ";
    cin>>a1.placa;
    cout<<"Datos ingresados del registro del automovil"<<endl;
    cout<<"Marca: "<<a1.marca<<"\t";
    cout<<"Modelo: "<<a1.modelo<<"\t";
    cout<<"Anyo: "<<a1.anyo<<"\t";
    cout<<"Placa: "<<a1.placa<<"\t";
}