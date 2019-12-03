#include <iostream>
#include <math.h>
#include <thread>
#define incrementos 1000000000000000000000000000000000000

using namespace std;

double i=1,seno,coseno,tangente,logaritmo,raiz;
void calculos(){
        while(i<incrementos){
        seno+=sin(i);
        coseno+=cos(i);
        tangente+=tan(i);
        logaritmo+=log(i);
        raiz+=sqrt(i);
        i++;
    }
}

int main(){
    thread th1(calculos);
    th1.join();
    return 0;
}