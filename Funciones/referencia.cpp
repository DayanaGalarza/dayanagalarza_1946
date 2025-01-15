#include <iostream>
using namespace std;

void operaciones (float num1, float num2, float &suma, float &resta, float &multiplicacion, float &division, int &resultado)
{
    suma = num1 + num2;
    resta = num1 - num2;
    multiplicacion = num1 * num2;
    division = num1 / num2;
    resultado = (int)num1 % (int)num2;
}

main()
{
    float a, b, suma, resta, multiplicacion, division;
    int residuo;

    cout << "Ingrese el primer numero: ";
    cin >> a;
    cout << "Ingrese el segundo numero: ";
    cin >> b;
    operaciones (a, b, suma, resta, multiplicacion, division, residuo);
    cout << "La suma de los numeros es: "<< suma << endl;
    cout << "La resta de los numeros es: "<< resta << endl;
    cout << "La multiplicaciom de los numeros es: "<< multiplicacion << endl;
    cout << "La division de los numeros es: "<< division << endl;
    cout << "El residuo de los numeros es: "<< residuo << endl;
}