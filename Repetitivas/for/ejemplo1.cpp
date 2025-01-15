#include <iostream>
using namespace std;

 main(){
    int i;
    for(i = 1; i<=10; i++)
    {
        cout<<i<<" ";
    }

    cout << endl;
    for (i=2; i<=10; i+=2)
    {
        cout<<i<<" ";
    }

    cout<<endl;
    for (i = 10; i >= 1; i--){
        cout<<i<<" ";
    }

    cout<<endl;
    for (i = 10; i >= 1; i-=2)
    {
        cout<<i<<" ";
    }

 }