#include <iostream>

using namespace std;

main ()
{
    int n1,n2,n3, n4;
    cout << "Ingrese un numero:" ;
    cin >> n1 ;
    cout << "Ingrese un numero:" ;
    cin >> n2 ;
    cout << "Ingrese un numero:" ;
    cin >> n3 ; 
     
    cout << "Los numeros ingresados son:" <<n1<<"," <<n2<<","<<n3<<endl;

    n4=n1 ;
    n1=n2 ;
    n2=n3 ;
    n3=n4 ;

    cout<< "Los resultados desplazados son:" <<n1<<"," <<n2<<","<<n3<<endl;

}