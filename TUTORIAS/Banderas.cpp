#include <iostream>
using namespace std;

main()
{
    bool bandera = true;
    bandera = !bandera;
    if (!bandera) {
        cout << "La bandera es falso" << endl;
    } else {
        cout << "La bandera es verdadera" << endl;
        }
}
