#include <iostream>
#include <unistd.h>
#include <thread>
#include <atomic>
#define incrementos 10000

using namespace std;

int variable=0;
int num;
//atomic<int> global(0);

void funcionInc(int var){
    for(int i=0;i<var;i++){
        variable++;
    }    
    //sleep(1);
}

void funcionDec(int var){
    for(int i=0;i<var;i++){
        variable--;
    }
    //sleep(1);
}
int main(){

    //atomic<int> var_local(10000);
    int var_local=10000,*dir;
    
    thread th1(funcionInc,&var_local),th2(funcionDec,&var_local);
    th1.join();
    th2.join();

    cout<<"El valor de la variable global es: "<<variable<<endl;
    return 0;
}