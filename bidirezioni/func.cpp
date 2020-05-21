#include "header.h"
void createNodo (int valore , NODO &right , NODO &left){
    NODO nuovo = new nodo;
    nuovo->valore = valore;
//---------------- right -------------------------------
    if(right == NULL ) {
        right = nuovo;
        left = nuovo;
        nuovo->next = NULL;
        nuovo->prev = NULL;

    }else{
          NODO app = right;
        while (app->next != NULL){
            app = app->next;
        }
        app->next = nuovo;
        left = nuovo;
        nuovo->next = NULL;
        nuovo->prev = app;
    }

}

void show (NODO right , NODO left){
    NODO appR = right;
    NODO appL = left;
    cout << " Tesat =>\t";
    while(appR != NULL){
        cout << appR->valore << "\t";
        appR = appR->next;
     }
    cout << "\n Coda =>\t";
    while(appL != NULL){
        cout << appL->valore << "\t";
        appL = appL->prev;

     }

}
