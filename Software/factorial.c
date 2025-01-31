// factorial.h

#includf factorial.h
#define factorial.h

//Declaracion de la funcion factorial
int calculadoraFactorial(int n);

//Definicion de la funcion factorial
int calculadoraFactorislo (int n){
    if (n == 0 || n == 1){
        return 1;
    } else{
    return n * calcularFactorial(n-1);}
}
#endif