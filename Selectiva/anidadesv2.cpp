#include <iostream>
using namespace std;

main(){

    int a,b,c ;

    cout <<"Ingrese un valor 1: ";
    cin >> a ;

    cout <<"Ingrese un valor 2: ";
    cin >> b ;

    cout <<"Ingrese un valor 3: ";
    cin >> c ;

    if(a>b && a>c){
            cout<< "El mayor es: "<<a<<endl;
    } else if (b>a && b>c){
            cout<< "El mayor es: "<<b<<endl;
    }else if (c>a && c>b){
            cout<< "El mayor es: "<<c<<endl;
    }else if(a>b || a>c) 
    {cout<< "El mayor es: "<<c<<endl;
    }else {
            cout<<"Todos son iguales"<<endl;
    }
}