#include <iostream>
using namespace std;

// cuerpo de las funciones (deine y declara la funcion)

int mayor (int a, int b)
{
    if (a > b)
        return a;
    else 
        return b;
}

float promedio(int a, int b)
{
    return (a + b) / 2.0;
}

void saludo (int hora)
{
    if (hora < 12)
    cout << "Buenos dias"<< endl;
    else if (hora < 19)
    cout << "Buenos dias"<< endl;
    else 
    cout << "Buenos noches"<<endl;
}


main()
{
    int n1, n2, hora;
    cout <<"Ingresa tres valores: " ;
    cin >> n1 >> n2>> hora;
    cout << "El mayor es: " << mayor (n1,n2) << endl;
    cout << "El promedio es: " << promedio (n1,n2) << endl;
    saludo (hora);
}
