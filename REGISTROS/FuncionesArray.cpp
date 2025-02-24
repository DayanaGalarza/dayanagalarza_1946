#include <iostream>
using namespace std;

struct persona
{
    int id;
    string nombre;
    int edad;
    bool casado = false;
};

void ingresaDatosRegistro(persona per[], int n)
{
    char resp;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        per[i].id = i + 1;
        cout << "Ingrese nombre: ";
        getline(cin, per[i].nombre);
        cout << "Ingrese edad: ";
        cin >> per[i].edad;
        cout << "Es casado? (s/n)";
        cin >> resp;
        cin.ignore();

        if (resp == 's' || resp == 'S')
            per[i].casado = true;
    }
}

void mostraDatosRegistro(persona per[], int n)
{
    cout << "ID\tNOMBRE\tEDAD\tCASADO" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << per[i].id << "\t";
        cout << per[i].nombre << "\t";
        cout << per[i].edad << "\t";
        (per[i].casado) ? cout << "SI" : cout << "NO";
    }
}

persona buscarPersona(persona per[], int n, int id)
{
    persona founded;
    for (int i = 0; i < n; i++)
    {
        if (per[i].id == id)
        {
            founded = per[i];
            return founded;
        }
    }
    return founded;
}

persona buscarPersonaPorNombre(persona per[], int n, string nombres)
{
    int i,j = 0, id;
    persona encontrados[10];
    persona encontrada;
    for (int i = 0; i < n; i++) // Se recorre correctamente el array
    {
        if (per[i].nombre.find(nombres) != string::npos)
        {
            encontrados[j] = per[i];
            j++;
            encontrada = per[i];
        }
    }

    cout << "Listado de personas encontradas: " << j << endl;
    for (int i = 0; i < j; i++)
    {
        cout << encontrados[i].id << "\t" << endl;
        cout << encontrados[i].nombre << "\t" << endl;
        cout << encontrados[i].edad << "\t" << endl;
        (encontrados[i].casado) ? cout << "SI" << endl : cout << "NO" << endl;
    }
    cout <<"Ingrese el Id de la persona que desea extraer: " ;
    cin >> id;
    encontrada = buscarPersona(encontrados,(j+1), id);

    return encontrada;
}

int main()
{
    int np, id;
    string nombre;
    cout << "Ingrese la cantidad de personas: ";
    cin >> np;
    cin.ignore();

    persona personas[np];
    ingresaDatosRegistro(personas, np);
    mostraDatosRegistro(personas, np);

    cout << "\nIngrese nomre de la persona a buscar";
    getline(cin, nombre);

    persona founded = buscarPersonaPorNombre(personas, np, nombre);
    if (founded.id == 0)
    {
        cout << "Persona no encontrada" << endl;
    }
    else
    {
        cout << "Persona encontrada" << endl;
        cout << "ID\tNOMBRE\tEDAD\tCASADO" << endl;
        cout << founded.id << "\t";
        cout << founded.nombre << "\t";
        cout << founded.edad << "\t";
        (founded.casado) ? cout << "SI" << endl : cout << "NO" << endl;
    }

    return 0;
}