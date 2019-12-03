#include <iostream>
#include <math.h>

using namespace std;

int main(){
    double i=1,seno,coseno,tangente,logaritmo,raiz;
    while(i<1000000000000000000000000000000000000){
        seno+=sin(i);
        coseno+=cos(i);
        tangente+=tan(i);
        logaritmo+=log(i);
        raiz+=sqrt(i);
        i++;
    }
    return 0;
}