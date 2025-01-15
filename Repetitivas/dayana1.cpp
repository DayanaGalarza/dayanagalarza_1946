#include <iostream>
using namespace std;

int main() {
    int numero;  
    bool s;      

    cout << "Introduce un número: ";
    cin >> numero;  

    
    if (numero != 0) {
        s = true;  
    } else {
        s = false; 
    }

    cout << "s = " << (s ? "verdadero" : "falso") << endl;

    return 0;
}
