#include <stdio.h>
#include <stdlib.h>

int main() {
    int habitantesViviendo[5][25];
    habitantesViviendo[3][24] = 4; 
    printf("El numero de personas que viven en ela vivienda 24 del piso 3 es: %d\n", habitantesViviendo[3][24]);
    return 0;
}
