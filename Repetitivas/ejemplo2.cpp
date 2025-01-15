/*programa que lee datos y muestra su promedio y el numero de datos que estan por debajo y encima del promedio*/
#include <iostream>
using namespace std;

main()
{
    int valor, promedio=0, contador=0;
    char op;
    bool bandera=false;
    while(!bandera) {
        cout<< "Deseas ingresar valores <<S>> <<N>>:" ;
        op = getchar();
        if (op == 's' || op== 'S'){
            cout<<"Ingrese el valor:";
            cin>>valor;
            contador++;
            promedio = promedio + valor;
        }else{
            bandera=true;
        }
        cin.ignore();
    }
    cout <<"El promedio de datos ingresados es " <<((float)promedio / contador)<<endl; 
}


