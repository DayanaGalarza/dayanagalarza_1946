#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <numeric> 

using namespace std;

struct Articulo {
    string nombre;
    double precio;
    vector<int> cantidadesVendidas; 
};

void leerDatos(vector<Articulo>& articulos) {
    string nombres[10] = {"Laptop", "Mouse", "Teclado", "Monitor", "Laptop", "Impresora", "Mouse", "Webcam", "Teclado", "Monitor"};
    double precios[10] = {1200.00, 25.00, 45.00, 250.00, 1200.00, 180.00, 25.00, 60.00, 45.00, 250.00};
    int cantidades[10][4] = {
        {5, 0, 0, 0},    
        {0, 15, 0, 0},   
        {0, 0, 8, 0},    
        {0, 0, 0, 3},    
        {0, 2, 0, 0},    
        {4, 0, 0, 0},    
        {0, 0, 20, 0},   
        {0, 0, 0, 6},    
        {10, 0, 0, 0},   
        {0, 7, 0, 0}     
    };

    for (int i = 0; i < 10; i++) {
        articulos[i].nombre = nombres[i];
        articulos[i].precio = precios[i];
        articulos[i].cantidadesVendidas = vector<int>(4);

        for (int j = 0; j < 4; j++) {
            articulos[i].cantidadesVendidas[j] = cantidades[i][j];
        }
    }
}

void calcularTotales(const vector<Articulo>& articulos, double& recaudacionTotalEmpresa, double recaudacionesSucursal[4], int& cantidadesSucursalSur, int& cantidadTecladoNorte) {
    recaudacionTotalEmpresa = 0; 
    for (int i = 0; i < 10; i++) {
        double recaudacionArticulo = 0;

        for (int j = 0; j < 4; j++) {
            recaudacionArticulo += articulos[i].cantidadesVendidas[j] * articulos[i].precio;
            recaudacionesSucursal[j] += articulos[i].cantidadesVendidas[j] * articulos[i].precio;

            if (j == 2) {
                cantidadesSucursalSur += articulos[i].cantidadesVendidas[j];
            }
            if (articulos[i].nombre == "Teclado" && j == 0) {
                cantidadTecladoNorte = articulos[i].cantidadesVendidas[j];
            }
        }
        recaudacionTotalEmpresa += recaudacionArticulo;
    }
}

int obtenerSucursalMayorRecaudacion(double recaudacionesSucursal[4]) {
    int sucursalMayor = 0;

    for (int i = 1; i < 4; i++) {
        if (recaudacionesSucursal[i] > recaudacionesSucursal[sucursalMayor]) {
            sucursalMayor = i;
        }
    }

    return sucursalMayor;
}

void guardarEnArchivo(const string& archivo, const vector<Articulo>& articulos, double recaudacionTotalEmpresa, double recaudacionesSucursal[4], int cantidadesSucursalSur, int cantidadTecladoNorte) {
    ofstream outFile(archivo);
    
    if (outFile.is_open()) {
        outFile << left << setw(5) << "ID" << setw(15) << "PRODUCTO" << setw(15) << "CANTIDAD TOTAL" 
                << setw(10) << "PRECIO" << setw(18) << "NORTE" << setw(15) << "CENTRO" 
                << setw(15) << "SUR" << setw(15) << "ESTE" << endl;

        outFile << "-------------------------------------------------------------------------------" << endl;

        int id = 1;
        
        // Escribimos los datos de cada artículo
        for (const auto& articulo : articulos) {
            outFile << left << setw(5) << id++ << setw(15) << articulo.nombre << setw(15) 
                    << accumulate(articulo.cantidadesVendidas.begin(), articulo.cantidadesVendidas.end(), 0) 
                    << setw(10) << fixed << setprecision(2) << articulo.precio;
            for (int j = 0; j < 4; j++) {
                outFile << setw(15) << articulo.cantidadesVendidas[j];
            }
            outFile << endl;
        }

        outFile << "\nRecaudación total de la empresa: " << fixed << setprecision(2) << recaudacionTotalEmpresa << endl;
        outFile << "Recaudación total por sucursal:\n";
        outFile << "Norte: " << fixed << setprecision(2) << recaudacionesSucursal[0] << endl;
        outFile << "Centro: " << fixed << setprecision(2) << recaudacionesSucursal[1] << endl;
        outFile << "Sur: " << fixed << setprecision(2) << recaudacionesSucursal[2] << endl;
        outFile << "Este: " << fixed << setprecision(2) << recaudacionesSucursal[3] << endl;

        outFile << "\nSucursal con mayor recaudación: ";
        switch (obtenerSucursalMayorRecaudacion(recaudacionesSucursal)) {
            case 0: outFile << "Norte"; break;
            case 1: outFile << "Centro"; break;
            case 2: outFile << "Sur"; break;
            case 3: outFile << "Este"; break;
        }

        outFile << "\nCantidad total de artículos vendidos en Sur: " << cantidadesSucursalSur << endl;
        outFile << "Cantidad de teclados vendidos en Norte: " << cantidadTecladoNorte << endl;

        outFile.close(); 
    } else {
        cout << "No se pudo abrir el archivo para escribir." << endl;
    }
}

int main() {
    vector<Articulo> articulos(10); 
    double recaudacionTotalEmpresa = 0;
    double recaudacionesSucursal[4] = {0}; 
    int cantidadesSucursalSur = 0;
    int cantidadTecladoNorte = 0;

    leerDatos(articulos);  

    calcularTotales(articulos, recaudacionTotalEmpresa, recaudacionesSucursal, cantidadesSucursalSur, cantidadTecladoNorte); // Calcular totales

    guardarEnArchivo("consolidado.txt", articulos, recaudacionTotalEmpresa, recaudacionesSucursal, cantidadesSucursalSur, cantidadTecladoNorte); // Guardar en archivo

    cout << "La informacion se ha guardado en el archivo consolidado.txt" << endl;

    return 0;
}
