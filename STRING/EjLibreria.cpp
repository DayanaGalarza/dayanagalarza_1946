#include <iostream>
#include "../LIBRERIAS/Stings.h"
using namespace std;

main()
{
    string palabras;
    cout<<"Ingrese una palabra: ";
    getline(cin, palabras);
    reemplazar(palabras);
    cout<<"La cadena final es: "<<palabras<<endl;
    return 0;
 
}