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

    if(a>b){
        if(a>c){
            cout<< "El mayor valor es: "<<a<<endl;
        }
        else{
            cout<<"El mayor valor es: "<<c<<endl;
        }
    }
    else{
        if(b>c){
            cout<<"El mayor valor es: "<<b<<endl;
        }
        else{
            if(c>a){
                cout<<"El mayor valor es: "<<c<<endl;
            }
           else{
            cout<<"Todos son iguales"<<endl;
           } 
        }
    }
}