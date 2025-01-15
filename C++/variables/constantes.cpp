#include <iostream>
#define GRAVEDAD 9.8 
using namespace std;

main()
{
    const int altura = 25 ;
    const float pi = 3.1416 ;
    const char letra = 'a' ;
    const string palabra = "hola mundo";
    enum colores {amarillo = 1, azul, rojo} ; //constantes numerica de tipo entero 
    cout <<"Las constantes definidas son : \n" ;
    cout << "altura ="<<altura<<endl ;
    cout << "pi ="<<pi<<endl ;
    cout << "letra ="<<letra<<endl ;
    cout << "amarillo ="<<amarillo<<endl ;
    cout << "azul ="<<azul<<endl ;
    cout << "rojo ="<<rojo<<endl ;
    cout << "La gravedad es ="<<GRAVEDAD<<endl;

}