#include <iostream>
#include <iostream>
using namespace std;
void llenarCadena (char cad [], int n=50 ){
    cout << "Ingresa una Cadena de caracteres: ";
    cin.getline (cad, n);
    cin.clear();
}
int longitudCadena (char cad []){
    int contador = 0;
for (int i=0; cad[i]!='\0'; i++)
    contador++;
    return contador;

}
int contarPalabras(char cad[]){
    int palabras = 0;
    bool palabra=false;

    for ( int i=0; cad[i]!='\0'; i++)
    {
        if(cad[i]== ' ' && (cad[i+1] != ' ' && (cad[i+1]!='\0')))
        {
            palabras++;
            palabra= true;
        }
    }
    (palabra) ? palabras++ : palabras;
    return palabra;
}
main ()
{
    char palabras [50];
    llenarCadena (palabras );
    cout << "La cadena ingresada es: " << palabras << endl;
    cout << "La longitud de la cadena es: " << longitudCadena(palabras) << endl;
    cout << "El numero de palabras en la cadena es: " << contarPalabras(palabras) << endl;
}