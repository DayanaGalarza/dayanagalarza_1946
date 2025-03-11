#include <iostream>
#include <vector>
using namespace std;
void cambiarValor(vector<vector<int>> &tabla )
{
    tabla[0][0] = 100;
}
main()
{
    vector<vector<int>> tabla(4, vector<int>(3, 1));
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << tabla[i][j] << " ";
        }
        cout<<endl;
    }
    cout<<"tabla modificada"<<endl;
    cambiarValor(tabla);
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << tabla[i][j] << " ";
        }
        cout<<endl;
    }
    
   
    
}