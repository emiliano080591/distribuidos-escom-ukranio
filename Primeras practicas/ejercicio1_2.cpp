#include<iostream>
using namespace std;

int main(){
    int dividendo,divisor,res;
    float numFlotante;

    cout<<"Dividendo:"; cin>>dividendo;
    cout<<"Divisor:"; cin>>divisor;

    cout<<"Resultado: "<<dividendo/divisor<<"\n";

    cout<<"Dividendo:"; cin>>dividendo;
    cout<<"Divisor:"; cin>>numFlotante; 


    cout<<"Resultado 2: "<<dividendo/numFlotante<<"\n";

    return 0;
}