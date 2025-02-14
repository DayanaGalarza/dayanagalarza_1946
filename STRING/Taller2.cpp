#include <iostream>
using namespace std;

main() 
{
    string cadena1={"informatica"};
    string cadena4;
    const char *auxiliar;
    string cadena2(cadena1); //cadena2 = cadena1
    string cadena3(10,'*');
    cadena1.push_back('y'); //añadir un solo caracter al final
    cout << cadena1 << endl;
    cadena1.at(0)= 'I'; //metodo at accede a un indice de la cadena1[0  ]
    cout << cadena1 << endl;
    //usando el metodo front y back para cambiar los carateres inicio y final
    cadena1.front()='i';
    cadena1.back()='A';
    cout << cadena1 << endl;
    auxiliar = cadena1.c_str(); //convierte un array de tipo string a un array de tipo char
    cout << "auxiliar array char: " << auxiliar << endl;
    //modo empty para conocer si una cadena esta vacia o no
    (cadena4.empty())?cout<<"Cadena Vacia\n": cout<< "Cadena no vacia\n";
    //tamaño maximo de caracteres que puede almacenar la cadena
    cout <<"Tamano maximo: " << cadena1.max_size()<<endl;
    //tamaño en bites del objeto string que ocupa actualmente
    cout << "Capacidad: " << cadena1.capacity()<<endl;
    //uando el metodo compare para comparar dos cadenas
    cout<<" cad1= "<<cadena1<<" cad2= "<<cadena2<<endl; 
    cadena1= "mola";
    cadena2 = "cola";
    int comparacion =cadena1. compare(cadena2);
    cout<<"Comparacion: " <<comparacion<<endl;
    int encontrado = cadena1.find("ol");
    cout<<"encontrado: "<<encontrado<<endl;
    (cadena1.find("ol")==string::npos)?cout<<"No encontrado ":cout<<encontrado; //:: accede a una libreria del tipo anterior como constante
    string numerostr= "123";
    int numero = stoi(numerostr);
    cout <<endl;
    cout << numero << endl;
    cin >> numero;
}
