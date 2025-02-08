#include <iostream> //<> es cuando se incluyen las librerias estandar de c++
#include "../LIBRERIAS/Series.h" //"" esa libreria no es propia del sistema, si no librerias creaas por el programador
using namespace std;

main(){
    cout << "El factorial de 5 es: " << factorial(5);
    cout << "El quinto termino de la serie de fibonaci es: " << fibonacci(5);
}