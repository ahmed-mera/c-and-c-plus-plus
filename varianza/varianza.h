//
// Created by Ahmed on 08/01/2020.
//

#ifndef VARIENZA_VARIENZA_H
#define VARIENZA_VARIENZA_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

class varianza {
public:
    // prepare  variables
    float somma = 0, sommaScarti = 0, media = 0 , mediaScarti = 0 , *arr , *arrScarti ;
    int dim;
    varianza () {
        cout << "inserire la dim :_";
        cin >> dim;
        cin.ignore();
        arr = new float[dim];
        arrScarti = new float[dim];

        varianza::carica_media(arr, dim);
        varianza::scarti_media(arrScarti, dim);
        cout << "Array 1 => ";
        varianza::showArr(arr,dim);
        cout << "media = ";
        varianza::showMedia(media);
        cout << "Array 2 => ";
        varianza::showArr(arrScarti,dim);
        cout << "media Scarti = ";
        varianza::showMedia(mediaScarti);
    };

    void carica_media(float * arr , int dim){
        srand(time(NULL));
        //somma = 0;
        for (int i = 0; i < dim; ++i) {
            arr[i] = ( rand()  - rand() ) % 10  ;
            somma += arr[i];
        }
        media = getMedia(somma);
    }


    void scarti_media (float * arrScarti , int dim){
        for (int i = 0; i < dim; ++i) {
            arrScarti[i] = arr[i] - media;
            sommaScarti += pow(arrScarti[i] , 2);
        }
        mediaScarti = getMedia(sommaScarti);
        mediaScarti = deviazione(mediaScarti);
    }

    float getMedia(float somma){ return somma / dim;}

    void showArr(float *arr, int dim){
        cout << "[";
        for (int i = 0; i < dim; ++i) {
            cout << arr[i] ;
            if(i != (dim - 1)) { cout << " , ";}
        }
        cout << "]" << endl;
    }

    void showMedia(float media){
        cout << media << endl;
    }

    float deviazione (float mediaScarti){ return sqrt(mediaScarti);}

};


#endif //VARIENZA_VARIENZA_H
