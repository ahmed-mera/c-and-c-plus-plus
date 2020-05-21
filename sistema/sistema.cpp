#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define dim 7

int clac (int a , int b , int c);
void control (int* a);
int main()
{
    //srand(time(NULL));

    int bit[dim] , i ;
        //bit[0] = 0;
        //bit[1] = 1;
        /*cout << "inserire l'elemento :_";
        cin >> bit[2];
        //bit[3] = 0;
        cout << "inserire l'elemento :_";
        cin >> bit[4];
        cout << "inserire l'elemento :_";
        cin >> bit[5];
        cout << "inserire l'elemento :_";
        cin >> bit[6];*/

        control(&bit[2]);
        control(&bit[4]);
        control(&bit[5]);
        control(&bit[6]);

        //clac elementi

        bit[0] = clac(bit[2] , bit[4] , bit[6]);
        bit[1] = clac(bit[2] , bit[5] , bit[6]);
        bit[3] = clac(bit[4] , bit[5] , bit[6]);

        cout << "la stringa controllata e' :\n";
        for ( i = 0 ; i < dim  ; i ++){
            cout << i << " ) "<< bit[i] << endl;
        }

    return 0;
}

int clac (int a , int b , int c){
    int res;
    if (a == b && a == c  ){
        res = a;
    }else if (a == b && a != c){
        res = c;
    }else if(a == c && a != b){
        res = b;
    }
    return res;
}

void control(int* a){
    while(1){
         cout << "inserire l'elemento :_";
         cin >> *a;
         if(*a == 0 || *a == 1){
            break;
         }else{
            cout << " inseremento non valido riprova :( \n" << endl;
         }
    }



}
