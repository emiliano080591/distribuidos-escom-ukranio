#include <iostream>
#include <unistd.h>
#include <thread>
#include <mutex>
#define incrementos 10000
//ejercicio 3 y 6
using namespace std;

int variable=0;
mutex m;

void funcionInc(){
    
    for(int i=0;i<incrementos;i++){
        m.lock();
        variable++;
        m.unlock();
    }    
    
    //sleep(1);
}

void funcionDec(){
   
    for(int i=0;i<incrementos;i++){
         m.lock();
        variable--;
        m.unlock();
    }
    
    //sleep(1);
}
int main(){
    thread th1(funcionInc),th2(funcionDec);
    //cout<<"Proceso principal espera a que los hilos terminen\n";
    th1.join();
    th2.join();

    cout<<"Variable global "<<variable<<endl;
    return 0;
}