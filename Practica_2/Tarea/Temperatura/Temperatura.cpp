#include "Temperatura.h"
#include <iostream>

using namespace std;


Temperatura::Temperatura(float c, float k, float f){
    this->celsius=c;
    this->farenheit=f;
    this->kelvin=k;
}

void Temperatura::setTempCelsius(float c)
{
    this->celsius=c;
}

void Temperatura::setTempFahrenheit(float f){
    this->farenheit=f;
}

void Temperatura::setTempKelvin(float k){
    this->kelvin;
}

void Temperatura::printCelsius(){cout<<"Celsius "<<this->celsius<<endl;}
void Temperatura::printFahrenheit(){cout<<"Fahrenheit "<<this->farenheit<<endl;}
void Temperatura::printKelvin(){cout<<"Kelvin "<<this->kelvin<<endl;}




