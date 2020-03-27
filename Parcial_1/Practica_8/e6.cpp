#include <iostream>
#include <unistd.h>
#include <thread>
#include <mutex>

using namespace std;

int variable = 0;

mutex m;

void incrementa(int n)
{
    for (int i = 0; i < n; i++)
    {
        m.lock();
        variable++;
        printf("%d\n", variable);
        m.unlock();
    }
}

void decrementa(int n)
{
    for (int i = 0; i < n; i++)
    {
        m.lock();
        variable--;
        printf(" \t%d\n", variable);
        m.unlock();

    }
}

int main()
{
    int n = 1000000;
    thread th1(incrementa, n), th2(decrementa, n);
    printf("Proceso principal espera que los hilos terminen.\n");
    th1.join();
    th2.join();
    printf("El hilo principal termina.\n");
    cout << "Valor final de la variable: " << variable << endl;
    exit(0);
}