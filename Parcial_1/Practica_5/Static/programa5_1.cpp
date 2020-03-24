#include <iostream>
#include <stdlib.h>

using namespace std;

class Fecha
{
    private:
        static int dia, mes, anio;
        static int vecesMuestF;
    public:
        static int getVecesMuestF();
        Fecha(int = 3, int = 4, int = 2014);
        void inicializaFecha(int, int, int);
        void muestraFecha();
};

int Fecha::vecesMuestF = 0;
int Fecha:: dia;
int Fecha:: mes;
int Fecha:: anio;

int Fecha::getVecesMuestF(){
    cout << "\ndía: " << dia << " mes: " << mes << " año: " << anio << endl;
    return vecesMuestF;
}

Fecha::Fecha(int dd, int mm, int aaaa)
{
    mes = mm;
    dia = dd;
    anio = aaaa;
}

void Fecha::inicializaFecha(int dd, int mm, int aaaa)
{
    anio = aaaa;
    mes = mm;
    dia = dd;
    return;
}

void Fecha::muestraFecha()
{
    cout << "La fecha es (dia-mes-anio): " << dia << "-" << mes << "-" << anio << endl;
    vecesMuestF++;
    return;
}

int main(){
    Fecha a, b, c;
    a.inicializaFecha(17,6,2000);
    a.muestraFecha();
    cout << "Se ha mandado llamar muestraFecha ()" << a.getVecesMuestF() << " veces\n";
    b.inicializaFecha(3,4,2014);
    b.muestraFecha();
    cout << "Se ha mandado llamar muestraFecha ()" << b.getVecesMuestF() << " veces\n";
    c.inicializaFecha(21,9,2000);
    c.muestraFecha();
    cout << "Se ha mandado llamar muestraFecha ()" << c.getVecesMuestF() << " veces\n";
    return 0;
}