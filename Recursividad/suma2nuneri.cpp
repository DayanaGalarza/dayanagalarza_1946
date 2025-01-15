#include <iostream>
using namespace std;

int suma (int a, int b){
    if ( b==0)
        return a;
    else 
        return suma (a+1, b-1);
}

main()
{
    int a, b;
    cout << "Ingrese el primer numero: ";
    cin >> a;
    cout << "Ingrese el segundo numero: ";
    cin >> b;
    cout << "La suma de: "<< suma(a,b)<< endl;
}