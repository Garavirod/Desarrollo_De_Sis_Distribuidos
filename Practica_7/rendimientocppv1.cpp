#include<iostream>
#include <string>
#include <algorithm>
using namespace std;
#define N 100000
string generteWord(){
    string t = "";
    char w1 = (char)(65 + rand() % (91 - 65));
    char w2 = (char)(65 + rand() % (91 - 65));
    char w3 = (char)(65 + rand() % (91 - 65));
    t += w1;
    t += w2;
    t += w3;
    return t; 
}

int getOcurrencias(string &cadenota)
{
    int counter = 0;
    size_t idxOcurr = cadenota.find("IPN");
    while (idxOcurr != std::string::npos){
        counter++;
        idxOcurr = cadenota.find("IPN", idxOcurr + 1, 2);
    }
    return counter;
}

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
