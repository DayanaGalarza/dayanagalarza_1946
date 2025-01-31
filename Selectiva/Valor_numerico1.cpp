#include <iostream>

int main() {
    int valor;
    
    std::cout << "Ingresa un valor numerico entre 1 y 20: ";
    std::cin >> valor;
    
    if (valor < 1 || valor > 20) {
        std::cout << "El valor numerico debe estar entre 1 y 20.\n";
        return 1; 
    }

    std::string categoria = (valor >= 1 && valor <= 5) ? "Deficiente" :
                            (valor >= 6 && valor <= 10) ? "Regular" :
                            (valor >= 11 && valor <= 15) ? "Bueno" :
                            (valor >= 16 && valor <= 18) ? "Muy bueno" : "Excelente";

    std::cout << "La categoria es: " << categoria << std::endl;
    
    return 0;
}