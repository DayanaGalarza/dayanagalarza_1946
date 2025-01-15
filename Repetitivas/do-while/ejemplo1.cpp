#include <iostream>
using namespace std;

main(){

    int num, valor;
    num = 1;

    do{
        cout<<num<<" ";
        num++;
    }while (num<=10);

    //validar para ingresar valores entre 1 y 10
    do{
        cout<<"\nIngresa un valor: ";
        cin>>valor;
        (valor < 10 || valor > 20) ? cout<<"Valor no valido, ingresa un valor entre 10 y 20": cout<<"Exito\n";
    }while(valor < 10 || valor > 20);
    cout<<"Ingresate el valor: " <<valor<<endl;
}