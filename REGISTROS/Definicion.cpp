#include <iostream>
using namespace std;
struct persona{
    string nombre="Sin nombre"; //componentes llamados miembros teniendo un nombre unico
    int edad=0;
    float estatura=0.0; 
}persona1,persona2; //ambito global, al final;

struct {
    string nombre;
    float nota;
}e1,e2;

void registro(){
    persona p5,p6;
}
main ()
{

    persona persona3,persona4; //de tipo local p3,p4. Persona es nuevo tipo de dato struct
    persona3.nombre = "Carlos Ortiz";
    persona3.edad = 28 ;
    persona3.estatura = 1.75;
    cout<<"Datos persona2 "<<endl;
    cout<<"Nombre :";
    getline(cin, persona4.nombre);
    cout<<"Edad :";
    cin>>persona4.edad;
    cout<<"Estatura :";
    cin>>persona4.estatura;
    cout<<"Datos ingresados"<<endl;
    cout<<"Nombre: "<<persona3.nombre<<"\t";
    cout<<"Edad: "<<persona3.edad<<"\t";
    cout<<"Estatura: "<<persona3.estatura<<"\n";
    cout<<"Nombre: "<<persona4.nombre<<"\t";
    cout<<"Edad: "<<persona4.edad<<"\t";
    cout<<"Estatura: "<<persona4.estatura<<endl;
    cout<<"Datos del estudiante No 1"<<endl;
    cout<<"Nombre: ";
    cin.ignore();
    getline(cin, e1.nombre);
    cout<<"Nota: ";
    cin>>e1.nota;
}