#include <iostream>
using namespace std;

int main() {
    int numero;  
    bool s;      

    cout << "Introduce un numero: ";
    cin >> numero;  


    s = (numero != 0) ? true : false;  

    cout << "s = " << (s ? "verdadero" : "falso") << endl;

    return 0;
}
