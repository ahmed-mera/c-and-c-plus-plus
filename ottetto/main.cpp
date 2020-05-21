#include <iostream>
#include <cmath>
using namespace std;
void check(int ottetto [] , int start = 0 , int end = 225);
int checkOttetto(int ottetto [] , int start , int end);

int main() {
    int ip [4], sottoRetti, bitPrestitio = 0, i, submask = 0, nHost, countHost = 0;

    for (int i = 0; i < 4 ; ++i) {
        cout << "inserire l'ottetto N." << i + 1 << ":_";
        cin >> ip[i];
    }
    cout << endl;
    check(ip);

    cout << "inserire il numero di sottoreti :_ ";
    cin >> sottoRetti;

    for( i = 0; bitPrestitio < sottoRetti;i++){
        bitPrestitio = pow(2,i);
    }
    bitPrestitio = i - 1;
    cout << "il numero di bit dell'ultimo ottetto: " << bitPrestitio << endl;
    for( i = 7; i > (7 - bitPrestitio); i--){
        submask += pow(2,i);
    }
    cout << "la subnet mask : 255.255.255." << submask << endl;
    nHost = 256 - submask;
    cout <<  "il numero di ogni sottorete: " <<  nHost << endl;
    int bit = 0;
    for(i = 0; i < sottoRetti; i++){
       cout << "la sottorete numero:" << i + 1 << endl;
        cout << "\tsubnetting N." << i + 1 << ": " ;
            for (int j = 0; j < 3 ; ++j) {
                cout << ip[j] << ".";
        }
        bit = (i == 0) ?  0 : ( bit + nHost) ;
        cout << bit << endl;

        cout << "\tprimo IP disponibile:" ;
        for (int j = 0; j < 3 ; ++j) {
            cout << ip[j] << ".";
        }
        cout << countHost + 1 << endl;

        countHost += nHost;

        cout << "\tultimo IP disponibile:" ;
        for (int j = 0; j < 3 ; ++j) {
            cout << ip[j] << ".";
        }
         cout << countHost - 2 << endl;

        cout << "\til broadcast:" ;
        for (int j = 0; j < 3 ; ++j) {
            cout << ip[j] << ".";
        }
        cout << countHost - 1 << endl;
    }
    cout << "---------------------------------------------------------------------------------------" << endl;
     bit = 0;
    for(i = 0; i < sottoRetti; i++){
        for (int j = 0; j < 3 ; ++j) {
            cout << ip[j] << ".";
        }
      bit = (i == 0) ?  0 : ( bit + nHost) ;
        cout << bit << endl;
    }
    return 0;
}

void check (int ottetto[] , int start , int end){
    if(ottetto[0] >= start && ottetto[0]<= end){
        if(ottetto[0] >= 0 && ottetto[0] <= 127){
            if ( checkOttetto(ottetto , start , end) ) {
                cout << "  class A" << endl;
            }
        } else  if(ottetto[0] >= 128 && ottetto[0] <= 191){
            if ( checkOttetto(ottetto , start , end) ) {
                cout << "  class B" << endl;
            }
        }else  if(ottetto[0] >= 192 && ottetto[0] <= 223){
            if ( checkOttetto(ottetto , start , end) ) {
                cout << "  class C" << endl;
            }
        }else  if(ottetto[0] >= 224 && ottetto[0] <= 239){
            if ( checkOttetto(ottetto , start , end) ) {
                cout << "  class D" << endl;
            }
        } else{
            if ( checkOttetto(ottetto , start , end) ) {
                cout << " class E" << endl;
            }
        }
    } else{
        cout << "ip non e' corretto :( " << endl;
    }
}

int checkOttetto(int ottetto [] , int start , int end){
    for (int i = 1; i < 4; ++i) {
        if (! ( (ottetto[i] >= start && ottetto[i]<= end) ) ) {
            cout << " ottetto non e' corretto :( => " << ottetto[i] << endl;
            exit(0);
            return 0;
        }
    }
    return 1;
}