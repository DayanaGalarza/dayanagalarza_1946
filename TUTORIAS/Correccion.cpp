#include <iostream>
using namespace std;
string escogeUsuario(){
    cout<<"Ingrese: piedra, papel o tijera"<<endl;
    string usuario="";
    do{
        cin>>usuario;
        if(usuario!="piedra" && usuario!="papel" && usuario!="tijera"){
            cout<<"Ingrese: piedra, papel o tijera"<<endl;
        }
    }while(usuario!="piedra" && usuario!="papel" && usuario!="tijera");
    return usuario;
}
string escogeComputadora(){
    int numero=rand()%3;
    string palabras[] = {"piedra", "papel", "tijera"};
    return palabras[numero];
}
string ganaRonda(string usuario, string maquina){
    string resultado;
    resultado=(usuario==maquina)? "empate":(usuario=="piedra" && maquina=="tijera")?"usuario":(usuario=="papel" && maquina=="piedra")?"usuario":(usuario=="tijera" && maquina=="papel")?  "usuario":"maquina";    
    return resultado;
}
string ganaJuego(int usuario, int maquina){
    string resultado;
    resultado=(usuario>maquina)? "usuario":(usuario<maquina)?"maquina":"empate";
    return resultado;
}
void empiezaJuego(int nivel){
    int ptosMaquina=0,ptosUsuario=0;
    cout<<"Bienvenido al juego de piedra, papel o tijera"<<endl;
    ptosMaquina = (nivel==2)? 1: (nivel==3)? 2: 0;
    string usuario,maquina,resultado;    
    for(int i=1;i<=5;i++)
    {
        cout<<"Ronda "<<i<<endl;
        usuario=escogeUsuario();
        maquina=escogeComputadora();
        ganaRonda(usuario,maquina);
        resultado=ganaRonda(usuario,maquina);
        if(resultado=="usuario"){
            cout<<"Ganaste esta ronda"<<endl;
            ptosUsuario++;
        }else if(resultado=="maquina"){
            cout<<"Perdiste esta ronda"<<endl;
            ptosMaquina++;
        }else{
            cout<<"Empate en esta ronda"<<endl;
        }
    } 
    cout<<"El ganador del juego es: "<<ganaJuego(ptosUsuario,ptosMaquina)<<endl;   
}   
main(){
    int nivel;
    cout<<"Ingresa el nivel de dificultad: 1, 2 o 3"<<endl;
    cin>>nivel;
     empiezaJuego(nivel);
}