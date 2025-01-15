#include <iostream>
using namespace std;

main()
{
    int n, contador, s , dato;
    cout<<"Ingrese cuantos datos vas a entgresar:";
    cin>>n;
    contador=0;
    s=0;
    while (contador<n){
        cout<<"Ingrese un valor:" ;
        cin>> dato;
        contador ++;
        s = s + dato;
    }
    cout<<"La suma de n de las repeticiones  es igual " << s <<endl;
}

