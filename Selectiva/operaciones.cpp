#include <iostream>
using namespace std;

main()
{
    int n1,n2;
    char operador;
    cout<<"Ingrese dato 1:";
    cin>>n1;

    cout<<"Ingrese dato 2:";
    cin>>n2;
    cout<<"Que operacion se va a realizar: <<+>>,<<->>,<<*>>,<</>>";

    switch ( operador ) {

        case '+':
            cout<<"La suma de "<<n1<<" con "<<n2<<" ="<<(n1+n2)<<endl;
            break;
        
        case '-':
            cout<<"La resta de "<<n1<<" con "<<n2<<" ="<<(n1-n2)<<endl;
            break;
        
        case '*':
            cout<<"El producto de "<<n1<<" con "<<n2<<" ="<<(n1*n2)<<endl;
            break;
        
        case '/':
            (n2==0)?cout<<"No existe division por cero": cout <<"La division de "<<n1<<" con "<<n2<<" ="<<(n1/n2)<<endl;
            break;
        defaul:
        cout<<"operador"<<operador<<"No valido" <<endl;

    }
}