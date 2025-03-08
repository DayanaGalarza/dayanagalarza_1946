#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    bool entrar = true;
    int op, cantidadNumeros, contadorverificador, numeroverificador, suma, contador;
    
    while (entrar) {
        cout << "Menu de opciones" << endl;
        cout << "1. Numeros Abundantes" << endl;
        cout << "2. Numeros Deficientes" << endl;
        cout << "3. Numeros Amigos" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingresa una opcion: ";
        cin >> op;
        
        if (op > 0 && op < 4) {
            cout << "Ingrese cantidad de numeros: ";
            cin >> cantidadNumeros;
            contador = 0;
            numeroverificador = 2;  // Start checking from 2
        }
        
        switch(op) {
            case 1:
                cout << "Numeros Abundantes:" << endl;
                while (contador < cantidadNumeros) {
                    contadorverificador = 1;
                    suma = 0;
                    while (contadorverificador < numeroverificador) {
                        if (numeroverificador % contadorverificador == 0) {
                            suma = suma + contadorverificador;
                        }
                        contadorverificador++;
                    }
                    if (suma > numeroverificador) {
                        cout << "Abundante: " << numeroverificador << endl;
                        contador++;
                    }
                    numeroverificador++;
                }
                break;
                
            case 2:
                cout << "Numeros Deficientes:" << endl;
                while (contador < cantidadNumeros) {
                    contadorverificador = 1;
                    suma = 0;
                    while (contadorverificador < numeroverificador) {
                        if (numeroverificador % contadorverificador == 0) {
                            suma = suma + contadorverificador;
                        }
                        contadorverificador++;
                    }
                    if (suma < numeroverificador) {
                        cout << "Deficiente: " << numeroverificador << endl;
                        contador++;
                    }
                    numeroverificador++;
                }
                break;
                
            case 3: {
                cout << "Numeros Amigos:" << endl;
                // For amicable numbers, we need a different approach
                int pairCount = 0;
                int testNum = 220;  // Starting with a number close to first amicable pair
                
                while (pairCount < cantidadNumeros) {
                    int sum1 = 0;
                    // Find sum of divisors of testNum
                    for (int j = 1; j < testNum; j++) {
                        if (testNum % j == 0) {
                            sum1 += j;
                        }
                    }
                    
                    // Skip if sum1 <= testNum or if it's too large
                    if (sum1 <= testNum || sum1 > 100000) {
                        testNum++;
                        continue;
                    }
                    
                    int sum2 = 0;
                    // Find sum of divisors of sum1
                    for (int j = 1; j < sum1; j++) {
                        if (sum1 % j == 0) {
                            sum2 += j;
                        }
                    }
                    
                    // Check if they form an amicable pair
                    if (sum2 == testNum) {
                        cout << "Par Amigo: " << testNum << " y " << sum1 << endl;
                        pairCount++;
                    }
                    
                    testNum++;
                }
                break;
            }
                
            case 4:
                entrar = false;
                break;
                
            default:
                cout << "Opcion no valida" << endl;
        }
        
        cout << endl << "Presione una tecla para continuar...";
        getch();
        system("cls");
    }
    
    return 0;
}