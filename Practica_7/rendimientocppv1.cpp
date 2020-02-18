#include<iostream>
#include <string>
#include <algorithm>
using namespace std;
#define N 100000
string generteWord(){
    string t = "";
    char w1 = (char)(65+rand()%(91-65));
    char w2 = (char)(65+rand()%(91-65));
    char w3 = (char)(65+rand()%(91-65));
    t += w1;
    t += w2;
    t += w3;
    return t; 
}


int main(int argc, char const *argv[])
{
     // EJERCICO 3
    srand (time(NULL));
    string cadenota = "";
    int counter = 0;
    for(int i =0; i<N; i++){ 
        string q = generteWord();
        cadenota += q;
        cadenota += " "; 
        if(q.compare("IPN")==0)
            counter++;
    }

    cout<<counter<<endl;
    return 0;
}
