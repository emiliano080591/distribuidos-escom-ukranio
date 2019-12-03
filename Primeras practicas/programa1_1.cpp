#include<iostream>
using namespace std;

int main(){
    int numeroDeLenguajes;

    cout<<"Hola!!.\n"<<"Bienvenido a C++\n";
    cout<<"Cuantos lenguajes de progrmacion dominas?";
    cin>>numeroDeLenguajes;

    if(numeroDeLenguajes<1){
        cout<<"Sereia recomendable que aprendieras un lenguaje sencillo...\n"<<"Por ejemplo C,aunque nada es imposible";
    }
    else{
        cout<<"Este curso sera sencillo para ti";
    }
    return 0;
}