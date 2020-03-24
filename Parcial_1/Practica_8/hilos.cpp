#include <iostream>
#include <unistd.h>
#include <atomic>
#include <thread>
using namespace std;

//int global = 0;

//atomic<int> global(0);



void funInc(int n, atomic<int> & local){
    for(register int i = 0; i < n ; i++)
        local += 1;
    sleep(1);
}
void funDec(int n, atomic<int> & local){
    for(register int i = 0; i < n ; i++)
    local -= 1;
    sleep(1);
}

int main(){
    atomic<int> local(0);
    long num = 1000000;
    //thread th1(funcion, 5), th2(funcion, 10);
    thread th3(funInc, num, ref(local)), th4(funDec, num, ref(local));
    cout  << "Proceso principal espera que los hilos terminen\n";
    th3.join();
    th4.join();
    cout << "Valor de global:" << local<< endl;
    exit(0);
}

