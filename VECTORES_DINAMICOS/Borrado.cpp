#include <iostream>
#include <vector>
using namespace std;

main(){
    vector<int> numeros(10);
    for (int i = 0; i <10; i++){
        numeros.push_back(i+1);
    }
    cout<<"Elemntos del vector: "<<endl;
    for (auto x: numeros){
        cout<<x<<" ";
    }
    cout<<"\nTamanio del vector: "<<numeros.size()<<endl;
    numeros.erase(numeros.begin()+3, numeros.begin()+6);
    for (auto x: numeros){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"Tamanio del vector: "<<numeros.size()<<endl;
}

