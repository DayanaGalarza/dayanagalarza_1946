#include <iostream>
using namespace std;

 main() {

    int a, b, c;
    cout << "Ingrese el valor de a: ";
    cin >> a;
    cout << "Ingrese el valor de b: ";
    cin >> b;
    cout << "Ingrese el valor de c: ";
    cin >> c;

    if (a >= b && a >= c) {
        cout << "El mayor es = " << a << endl;
    } else if (b >= a && b >= c) {
        cout << "El mayor es = " << b << endl;
    } else {
        cout << "El mayor es = " << c << endl;
    }
    if (a == b && b == c) {
        cout << "Los valores son iguales" << endl;
    } 
}