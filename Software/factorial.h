//factorial.h

#ifndef FACTORIAL_H_INCLUDED
#define FACTORIAL_H_INCLUDED
//declaracion de la funcion 
int CalcularFactorial(int n);
int calcularfacorial(int n){
    if(n == 0||n == 1){
        return 1;}
        else{
        return n*calcularfacorial(n-1);
        }
    }

#endif // FACTORIAL_H_INCLUDED