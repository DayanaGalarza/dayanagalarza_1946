#include <iostream>
using namespace std;
main ()
{
    int anios [5]; //declaracion de un vector de 5 elementos 
    int edad [5] = {20,25,30,35,40}; //declaracion de un vector de 5 elementos 
    double estatura [] = {1.25, 1.66, 1.78, 1.70, 1.90}; //declaracion de un vector de 5 elementos 
    char sexo [5] = {'M', 'F', 'M', 'F', 'M' };
    cout << "El primer elemnto del vector edad es :" <<endl<<edad[0]<<endl;
    cout << "El primer elemnto del vector estatura es :" <<endl<<estatura[4]<<endl;
    cout << "El primer elemnto mitad sexo es :" <<endl<<sexo[5/2]<<endl;
    return 0;
}
for (int i = 0 ;)