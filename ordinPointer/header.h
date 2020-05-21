#include <iostream>
#include <malloc.h>
#include <string.h>
#define MAX_SIZE 15

using namespace std;

class LISTE {
    public:
        /**
        * ! Qua la dichiarzione della struttura
        **/
        struct nodo {
            char nome[MAX_SIZE] , cognome[MAX_SIZE];
            struct nodo* NEXT;
        };
        nodo* NUOVO;     /* PUNTATORI */
        nodo* HEAD;     /* PUNTATORI */


        LISTE ();     /* construct for my class*/

/**
 * !!! All functions
 * TODO CREATENODO(), ORDINANOME(), ORDINACOGNOME();
 **/
//void inserire(nodo*& NUOVO , nodo*& head);
void createNodo();
void ordinaNomi();
void ordinaCognomi();
void show();
};

