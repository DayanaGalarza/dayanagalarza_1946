#include <iostream>
#include <conio.h>
using namespace std;

main()
{
    bool entrar = true;
    int op, cantidadNumeros, contadorverificador, numeroverificador, suma, contador;
    while (entrar){
        cout << "Menu de opciones"<<endl;
        cout << "1. Numeros Abundantes"<<endl;
        cout << "2. Numeros Deficientes"<<endl;
        cout << "3. Numeros Amigos"<<endl;
        cout << "4. Salir"<<endl;
        cout << "Ingresa una opcion:";
        cin >> op; 

        if (op>0 && op<4) {
            cout<< "Ingrese cantidad de numeros: ";
            cin>>cantidadNumeros;
            contador=0;
            numeroverificador=2;
        }

        switch(op){
            case 1:
                while (contador < cantidadNumeros)
                contadorverificador=1;
                suma=0;
                while (contadorverificador < numeroverificador){
                    if(numeroverificador % contadorverificador==0){
                        suma= suma+contadorverificador;
                    }
                    contadorverificador++;
                }
                if(suma>numeroverificador){
                    cout<<"Abundante"<<numeroverificador<<endl;
                    contador++;
                }
                numeroverificador++;
            }
                break;
            case 2:
                cout<<"Deficientes"<<endl;
                break;
            case 3:
                cout<<"Amigo"<<endl;
                break;
            case 4:
                entrar = false;
                break;
            default:
                cout<<"Opcion no valida";
                

        system("pause");
        system("cls");
        }
    }
    