#include <iostream>
using namespace std;

int potencia (int a, int b){
    if ( b==0)
        return 1;
    else 
        return a * potencia (a, b-1);
}

main()
{
    int a, b;
    cout << "Ingrese el numero de la base: ";
    cin >> a;
    cout << "Ingrese el numero del exponente: ";
    cin >> b;
    cout << "La Potencia de " << potencia(a,b)<< endl;

}
