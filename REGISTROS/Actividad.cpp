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


struct {
    string nombre;
    string apellidoPaterno;
    string apellidoMaterno;
    string direccion;
    string nacionalidad;
    string grupoSanguineo;
    string reestricciones;
    int fechaDesde;
    int fechaVencimiento;
    int tipoDeLincencia ;
    int cedula;
}lm1;

struct {
    string nombre;
    string fechaDeVencimiento;
    int numeroDeTarjeta;
    int saldo;
    int limite;
}tj1;

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

    cout<<"Datos del Licencia de Manejo"<<endl;
    cout<<"Nombre: ";
    getline(cin, lm1.nombre);
    cout<<"Apellido Paterno: ";
    getline(cin, lm1.apellidoPaterno);
    cout<<"Apellido Materno: ";
    getline(cin, lm1.apellidoMaterno);
    cout<<"Direccion: ";
    getline(cin, lm1.direccion);
    cout<<"Nacionalidad: ";
    getline(cin, lm1.nacionalidad);
    cout<<"Grupo Sanguineo: ";
    getline(cin, lm1.grupoSanguineo);
    cout<<"Restricciones: ";
    getline(cin, lm1.reestricciones);
    cout<<"Fecha Desde: ";
    cin>>lm1.fechaDesde;
    cout<<"Fecha Vencimiento: ";
    cin>>lm1.fechaVencimiento;
    cout<<"Datos ingresados de la licencia de Manejo"<<endl;
    cout<<"Nombre: "<<lm1.nombre<<"\t";
    cout<<"Apellido Paterno: "<<lm1.apellidoPaterno<<"\t";
    cout<<"Apellido Materno: "<<lm1.apellidoMaterno<<"\t";
    cout<<"Direccion: "<<lm1.direccion<<"\t";
    cout<<"Nacionalidad: "<<lm1.nacionalidad<<"\t";
    cout<<"Grupo Sanguineo: "<<lm1.grupoSanguineo;

    cout<<"Datos de la Tarjeta de Credito"<<endl;
    cout<<"Nombre: ";
    getline(cin, tj1.nombre);
    cout<<"Fecha de Vencimiento: ";
    getline(cin, tj1.fechaDeVencimiento);
    cout<<"Numero de Tarjeta: ";
    cin>>tj1.numeroDeTarjeta;
    cout<<"Saldo: ";
    cin>>tj1.saldo;
    cout<<"Limite: ";
    cin>>tj1.limite;
    cout<<"Datos ingresados de la Tarjeta de Credito"<<endl;
    cout<<"Nombre: "<<tj1.nombre<<"\t";
    cout<<"Fecha de Vencimiento: "<<tj1.fechaDeVencimiento<<"\t";
    cout<<"Numero de Tarjeta: "<<tj1.numeroDeTarjeta<<"\t";
    cout<<"Saldo: "<<tj1.saldo<<"\t";
    cout<<"Limite: "<<tj1.limite;
}

