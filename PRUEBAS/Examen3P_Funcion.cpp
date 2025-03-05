#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

string ordenarPorLongitud(const string &cadena) {
    vector<string> palabras;
    stringstream ss(cadena);
    string palabra;
    
    while (ss >> palabra) {
        palabras.push_back(palabra);
    }
    
    sort(palabras.begin(), palabras.end(), [](const string &a, const string &b) {
        return a.size() > b.size();
    });
    
 
    string resultado;
    for (size_t i = 0; i < palabras.size(); i++) {
        resultado += palabras[i] + (i < palabras.size() - 1 ? " " : "");
    }
    
    return resultado;
}

int main() {
    string cadena = "uno quince doce";
    string resultado = ordenarPorLongitud(cadena);
    cout << "Cadena ordenada: " << resultado << endl;
    return 0;
}
