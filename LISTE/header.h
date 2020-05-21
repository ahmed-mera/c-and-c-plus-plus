/* include all libraries */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/* new list */
typedef struct list {
    int value;
    struct list* POINTER;
}nodo;


/* include the prototypes (**) ===> (*&)*/
nodo* createNodo ();
int menu(nodo** head);
void show (nodo* head);
void insertFront (nodo* newList , nodo** head);
void insertBack (nodo* newList , nodo** head);
void deleteFront (nodo** head);
void deleteBack (nodo** head);


