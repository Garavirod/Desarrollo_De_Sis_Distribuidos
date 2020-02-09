#include <unistd.h>
#include <iostream>
using namespace std;
class NumerosRand
{
  private:
    int *arreglo;
    unsigned int numeroElementos;

  public:
    NumerosRand(unsigned int num);
    void inicializaNumerosRand(void);
    ~NumerosRand();
};
NumerosRand::NumerosRand(unsigned int num)
{
    numeroElementos = num;
    arreglo = new int[numeroElementos];
}
void NumerosRand::inicializaNumerosRand()
{
    unsigned int i;
    for (i = 0; i < numeroElementos; i++)
        arreglo[i] = rand();
    return;
}

NumerosRand::~NumerosRand(){
    delete[] arreglo;
    cout<<"¡SE ELIMINO ESPACIO!"<<endl;
}
void pruebaClase()
{
    unsigned int capacidad;
    cout << "Numero de enteros aleatorios en el arreglo : ";
    cin >> capacidad;
    NumerosRand tmp(capacidad);
    tmp.inicializaNumerosRand();
    sleep(3);
}
int main()
{
    char res;
    do
    {
        pruebaClase();
        cout << "Probar de nuevo? (s/n) ";
        cin >> res;
    } while ((res == 's') || (res == 'S'));
}


/*
    PREGUNTA 1

    Se va  ocupando cada vez mas espacio en en memoria para reservar el espacio de cada arreglo de numero random

    PREGUNTA 2

    El arreglo se queda vacio, sin embargo ya se recerbó espacio en la memeoria para diho arreglo


    PREGUNTA 3

   Se va llenado mas la memeoria ya que no se va liberando

    PREGUNTA 4

    Se recerva espacio para los 100 millones además de los cien elementos, siendo el de 100 millones mas significativo en la memeoria


*/