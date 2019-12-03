#ifndef SEMAFORO_H_
#define SEMAFORO_H_
#include <mutex>
#include <condition_variable>

using namespace std;

class Semaforo
{
private:
    mutex mutex_;
    condition_variable condition;
    unsigned long count;
public:
    Semaforo(unsigned long=0);
    void post();
    void wait();
    void init(unsigned long);
};

#endif