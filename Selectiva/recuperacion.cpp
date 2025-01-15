#include <iostream>
using namespace std;

int 
main()
 {
    int n1, n2;
    char operacion;

    // Solicitar datos
    cout << "Ingrese el primer numero: ";
    cin >> n1;

    cout << "Ingrese el segundo numero: ";
    cin >> n2;

    cout << "Ingrese un caracter para la operacion (+ , - , * , /): ";
    cin >> operacion;

    // Operaciones
     switch (operacion) 
    {
        case '+':
        case 'suma':
            cout << "Resultado de la suma: " << (n1 + n2) << endl;
            break;
        case '-':
        case 'resta':
            cout << "Resultado de la resta: " << (n1 - n2) << endl;
            break;
        case '*':
        case 'multiplicacion':
            cout << "Resultado de la multiplicacion: " << (n1 * n2) << endl;
            break;
        case '/':
        case 'division':
            if (n2 == 0) 
            {
                cout << "Error: No se puede dividir entre cero." << endl;
            } 
            else
            {
                cout << "Resultado de la division: " << (n1 / n2) << endl;
            }
            break;
        default:
            cout << "Operación no valida." << endl;
    }