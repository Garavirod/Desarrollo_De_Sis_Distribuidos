#include "Temperatura.h"
#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    Temperatura t;
    t.setTempCelsius(23.9);
    t.printCelsius();
    return 0;
}
