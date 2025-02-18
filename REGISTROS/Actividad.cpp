#include <iostream>
using namespace std;

struct {
    string marca;
    string modelo;
    int anyo;
    string placa;
}a1;

struct {
    string nombre;
    string direccion;
    int telefono;
    int adeuda;
    int codigoci;
}cv1;


main ()
{
    cout<<"Datos del automovil"<<endl;
    cout<<"Marca: ";
    getline(cin, a1.marca);
    cout<<"Modelo: ";
    getline(cin, a1.modelo);
    cout<<"Anyo: ";
    cin>>a1.anyo;
    cout<<"Placa: ";
    cin>>a1.placa;
    cout<<"Datos ingresados del registro del automovil"<<endl;
    cout<<"Marca: "<<a1.marca<<"\t";
    cout<<"Modelo: "<<a1.modelo<<"\t";
    cout<<"Anyo: "<<a1.anyo<<"\t";
    cout<<"Placa: "<<a1.placa;
}

main ()
{
    cout<<"Datos del Cliente de Videoclub"<<endl;
    cout<<" Nombre: ";
    getline(cin, cv1.nombre);
    cout<<"Direccion: ";
    getline(cin, cv1.direccion);
    cout<<"Anyo: ";
    cin>>a1.anyo;
    cout<<"Placa: ";
    cin>>a1.placa;
    cout<<"Datos ingresados del registro del automovil"<<endl;
    cout<<"Marca: "<<a1.marca<<"\t";
    cout<<"Modelo: "<<a1.modelo<<"\t";
    cout<<"Anyo: "<<a1.anyo<<"\t";
    cout<<"Placa: "<<a1.placa;
}