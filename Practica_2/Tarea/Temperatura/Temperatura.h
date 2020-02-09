#ifndef TEMPERATURA_H_
#define TEMPERATURA_H_

class Temperatura
{
private:
    float farenheit;
    float kelvin;
    float celsius;
public:
    Temperatura(float=0.0,float=0.0,float=0.0);
    void setTempFahrenheit(float);
    void setTempKelvin(float);
    void setTempCelsius(float);
    void printKelvin();
    void printCelsius();
    void printFahrenheit();
};
#endif
