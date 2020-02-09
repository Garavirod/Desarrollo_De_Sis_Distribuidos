#include<iostream>
#include <string>
#include<math.h>
using namespace std;


// Ejercio 1
double sqrtBabilonico (double n){
    double r = n;
    double t = 0;
    while(t!=r){
        t = r;
        r = ((n/r)+r)/2;
    }
    return r;
    
}

// Ejercio 2
double altura(double t){return (9.81*pow(t,2));}

// Ejercio 3
void conversor(int s){
    int horas, min, seg, residuo;
    horas =  s/3600;
    residuo = s%3600;
    min = residuo/60;
    seg = residuo%60;
    cout<<"Horas ["<<horas<<"] Minutos ["<<min<<"] Segundos ["<<seg<<"]"<<endl;
    
}


int main(){

    double num, seg;
    int seg2;
    cout<<"Raíz cuadrada de >: "<<endl;
    cin>>num;
    cout<<sqrtBabilonico(num)<<endl;

    cout<<"Tiempo >: ";
    cin>>seg;
    cout<<"Altura del edificio "<<altura(seg)<<endl;

    cout<<"Conversor de tiempo >: ";
    cin>>seg2;
    conversor(seg2);
    return 0;        
}
