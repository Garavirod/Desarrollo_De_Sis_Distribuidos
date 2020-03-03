#include<iostream>
#include <string>
#include <algorithm>
#include "renidmiento.h"
using namespace std;
#define N 50000000

int main(int argc, char const *argv[])
{
    // EJERCICO 3
    srand(time(NULL));
    string cadenota = "";
    for(int i =0; i<N; i++){ 
        cadenota += generteWord();
        cadenota += " "; 
    }
    std::cout<<"Número de ocurrencias >: "<<getOcurrencias(cadenota)<<endl;
    
    return 0;
}
