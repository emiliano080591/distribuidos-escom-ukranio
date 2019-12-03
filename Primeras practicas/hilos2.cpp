#include <iostream>
#include <unistd.h>
#include <thread>
#include <atomic>
#define incrementos 10000

using namespace std;
//ejercicio 5
int variable=0;
int num;
//atomic<int> global(0);

void funcionInc(atomic<int>& variable){
    for(int i=0;i<incrementos;i++){
        variable++;
    }    
    //sleep(1);
}

void funcionDec(atomic<int>& variable){
    for(int i=0;i<incrementos;i++){
        variable--;
    }
    //sleep(1);
}
int main(){

    atomic<int> var_local(0);
    thread th1(funcionInc,ref(var_local)),th2(funcionDec,ref(var_local));
    th1.join();
    th2.join();

    cout<<"El valor de la variable global es: "<<var_local<<endl;
    return 0;
}