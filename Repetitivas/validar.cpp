#include <iostream>
using namespace std;


main()
{
    int valor;
    while (true){
        cout<<"Ingrese un valor:";
        cin>>valor;
        if (valor >=2 && valor <=8){
            break;
        }
}
    int contador=0 ;
    char op;
    bool bandera=false;
    while(!bandera) {
        cout<< "Deseas ingresar valores <<S>> <<N>>:" ;
        op = getchar();
        if (op == 's' || op== 'S'){
            cout<<"Ingrese el valor:";
            cin>>valor;
            contador++;
        }else{
            bandera=true;
        }
        cin.ignore();
    }
    cout <<"Cuantos numeros estan fuera del intervalo " <<(valor)<<endl; 
}





