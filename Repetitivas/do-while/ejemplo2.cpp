#include <iostream>
using namespace std;

main(){
    int op;
    while (true){
    do{
        cout << "Menu de opciones" << endl;
        cout << "1. Abundantes" << endl;
        cout << "2. Deficientes" << endl;
        cout << "3. Amigos" << endl;
        cout << "4. Salir" << endl;
        cout << "Escoja una opcion: ";
        cin >> op;
        if(op<1 || op>4){
            cout<<"Opcion no valida";
            system("pause");
            system("cls");
        }

    }while (op<1 || op<4);
    switch (op)
    {
    case 1:
        cout << "Abundantes";
        break;
    case 2:
        cout << "Deficientes";
        break;
    case 3:
        cout << "Amigos";
        break;
    case 4:
        cout << "Saliendo del sistema";
        
    }

    system ("pause");
    system("cls");
    if(op==4);
    break;
}

}
