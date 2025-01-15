#include <iostream>
using namespace std;
main()
{
    int dia ;
    cout <<"Ingrese dia de la semana:" ;
    cin >> dia ;
    switch (dia)
    {

    case 1:
        cout <<"Es lunes" <<endl ;
        //break ;

    case 2:
        cout <<"Es martes" <<endl ;
        //break ;

    case 3:
        cout <<"Es miercoles" <<endl ;
        //break ;

    case 4:
        cout <<"Es jueves" <<endl ;
        break ;

    case 5:
        cout <<"Es viernes" <<endl ;
        break ;
    
    case 6:
        cout <<"Es sabado" <<endl ;

    case 7:
        cout <<"Es fin de semana" <<endl ;
        break;
    
    default:
         cout <<"Dia no valido" <<endl ;

    }
}