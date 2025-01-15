#include  <iostream> 
using namespace std;
main() {

int s, num, contenedor;
double x= 0;
num = 2;
double den = 1;
contenedor = 1;

cout << "Ingrese el numero de la serie: "; 
cin>>s;
cout << "La serie es:";

while (contenedor <= s){
    if (contenedor>1){
    if (contenedor % 2 ==0){ 
        cout<<"-";}
    else {
cout<<"+";
}
}
cout << num <<"/"<< den;

if (contenedor % 2 == 0)
{
x-=(num/den);
}
else
{
x+= (num/den);
}
num= num+den;
den += 2;

contenedor++;
}
cout<< endl;

cout <<"El valor de la serie de x es:" << x << endl;
}
