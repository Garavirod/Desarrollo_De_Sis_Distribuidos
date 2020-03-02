#include <iostream>
#include <unistd.h>
#include <thread>

using namespace std;

int v = 0;

void incrementa(){
    v++;
    sleep(1);
}

void decrementa(){
    v--;
    sleep(1);
}


void funcion(int valor){
    // cout<<"Hilo"<<this_thread::get_id()<<"Valor recibido "<<valor<<endl;
    printf("Hilo %ld valor recibido %d",this_thread::get_id,valor);
    sleep(2);
}

int main(int argc, char const *argv[])
{
//    EJERCICIO 1
    thread th1(funcion, 5), th2(funcion, 10);
    printf("Proceso principal espera que los hilos terminó\n");
    th1.join();
    th2.join();
    printf("El hilo principal terminó\n");

    // thread th1(incrementa), th2(decrementa);
    // th1.join();
    // th2.join();
    // cout<<"Valor de la variable "<<v<<endl;

    exit(0);
}
