#include <iostream>
using namespace std;

int multiplicacion (int a, int b){
    if ( b==0)
        return 0;
    else 
        return a + multiplicacion (a, b-1);
}

main()
{
    int a, b;
    cout << "Ingrese el numero de la base: ";
    cin >> a;
    cout << "Ingrese el numero del exponente: ";
    cin >> b;
    cout << "La Multiplicacion de " << multiplicacion (a,b)<< endl;

}